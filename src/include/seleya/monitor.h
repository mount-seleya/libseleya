#ifndef SELEYA_MONITOR_H
#define SELEYA_MONITOR_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>

typedef struct seleya_monitor_t seleya_monitor_t;

struct seleya_monitor_t {
  GLFWmonitor *monitor;
  const char *name;
  int primary;
  seleya_monitor_t *next;
};

seleya_monitor_t *seleya_monitor_new(GLFWmonitor *m);

#endif
