#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"
#include "seleya/window.h"

seleya_window_t *seleya_window_create(int w, int h, char *title, seleya_monitor_t *m)
{
  seleya_window_t *window = NULL;

  window = malloc(sizeof(seleya_window_t));
  if(!window)
    return NULL;

  memset(window, 0, sizeof(seleya_window_t));
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  window->w = w;
  window->h = h;

  if(m)
    window->window = glfwCreateWindow(w, h, title, m->monitor, NULL);
  else
    window->window = glfwCreateWindow(w, h, title, NULL, NULL);

  return window;
}
