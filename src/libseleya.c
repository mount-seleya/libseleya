#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <string.h>
#include <GLFW/glfw3.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"

seleya_monitor_t *seleya_init(void)
{
  GLFWmonitor **m;
  seleya_monitor_t *monitor = NULL, *monitor_next = NULL;
  int c = 0, i;

  glfwInit();
  m = glfwGetMonitors(&c);
  for(i = 0; i <= c; ++i)
  {
    monitor_next = seleya_monitor_new(m[i]);
    if(monitor_next)
    {
      if(monitor)
        monitor->next = monitor_next;
      else
        monitor = monitor_next;
    }
  }

  return monitor;
}
