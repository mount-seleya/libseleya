#ifndef SELEYA_H
#define SELEYA_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>

#include "seleya/monitor.h"

GLFWwindow *seleya_create_window(int w, int h, char *title);
seleya_monitor_t *seleya_init(void);

#endif
