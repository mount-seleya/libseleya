#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include "seleya/window.h"
#include "seleya/vulkan.h"

seleya_vulkan_t *seleya_vulkan_init(seleya_window_t *w, char *name, char *engine)
{
  seleya_vulkan_t *vk = NULL;
  VkApplicationInfo info;
  VkInstanceCreateInfo ici;

  memset(&info, 0, sizeof(VkApplicationInfo));
  memset(&ici, 0, sizeof(VkInstanceCreateInfo));
  vk = malloc(sizeof(seleya_vulkan_t));
  if(!vk)
    return NULL;

  memset(vk, 0, sizeof(seleya_vulkan_t));

  info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  info.pApplicationName = name;
  info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  info.pEngineName = engine;
  info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  info.apiVersion = VK_API_VERSION_1_0;

  ici.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  ici.pApplicationInfo = &info;

  vkCreateInstance(&ici, NULL, &vk->instance);
  glfwCreateWindowSurface(vk->instance, w->window, NULL, &vk->surface);

  return vk;
}
