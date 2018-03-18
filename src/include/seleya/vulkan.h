#ifndef SELEYA_VULKAN_H
#define SELEYA_VULKAN_H

#include <vulkan/vulkan.h>

#include "seleya/seleya.h"

typedef struct {
  VkSurfaceKHR surface;
  VkInstance instance;
} seleya_vulkan_t;


seleya_vulkan_t *seleya_vulkan_init(seleya_window_t *w, char *name, char *engine);

#endif
