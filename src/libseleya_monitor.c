#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"

seleya_monitor_t *seleya_monitor_new(GLFWmonitor *m)
{
  seleya_monitor_t *monitor;

  monitor = malloc(sizeof(seleya_monitor_t));
  if(!monitor)
    return NULL;

  memset(monitor, 0, sizeof(seleya_monitor_t));
  monitor->name = glfwGetMonitorName(m);

  return monitor;
}
