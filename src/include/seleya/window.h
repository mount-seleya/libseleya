#ifndef SELEYA_WINDOW_H
#define SELEYA_WINDOW_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>

#include "seleya/monitor.h"

typedef struct {
  GLFWwindow *window;
  int w;
  int h;
} seleya_window_t;

seleya_window_t *seleya_window_create(int w, int h, char *title, seleya_monitor_t *m);

#endif
