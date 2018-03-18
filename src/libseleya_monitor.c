#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"

void seleya_monitor_destroy(seleya_monitor_t *m)
{
  seleya_monitor_mode_t *mm = NULL;

  while(m->modes)
  {
    mm = m->modes;
    m->modes = m->modes->next;

    free(mm);
  }

  free(m);
}

seleya_monitor_t *seleya_monitor_new(GLFWmonitor *m)
{
  seleya_monitor_t *monitor = NULL;
  GLFWmonitor *primary = NULL;
  const char *primary_name = NULL;
  const GLFWvidmode *vm = NULL;
  seleya_monitor_mode_t *mode_next = NULL;
  int c, i;

  if(m)
  {
    monitor = malloc(sizeof(seleya_monitor_t));
    if(!monitor)
      return NULL;

    memset(monitor, 0, sizeof(seleya_monitor_t));
    monitor->monitor = m;
    monitor->name = glfwGetMonitorName(m);

    primary = glfwGetPrimaryMonitor();
    primary_name = glfwGetMonitorName(primary);

    if(strcmp(monitor->name, primary_name) == 0)
      monitor->primary = 1;

    vm = glfwGetVideoModes(m, &c);
    for(i = 0; i <= c; ++i)
    {
      mode_next = seleya_monitor_mode_new(m, &vm[i]);
      if(mode_next)
      {
        if(monitor->modes)
          mode_next->next = monitor->modes;

        monitor->modes = mode_next;
      }
    }
  }

  return monitor;
}

seleya_monitor_mode_t *seleya_monitor_mode_new(GLFWmonitor *m, const GLFWvidmode *vm)
{
  seleya_monitor_mode_t *mode = NULL;
  const GLFWvidmode *current = NULL;

  if(vm)
  {
    mode = malloc(sizeof(seleya_monitor_mode_t));
    if(!mode)
      return NULL;

    memset(mode, 0, sizeof(seleya_monitor_mode_t));
    mode->w = vm->width;
    mode->h = vm->height;
    mode->refresh_rate = vm->refreshRate;

    current = glfwGetVideoMode(m);
    if(current && current->width == vm->width &&
        current->height == vm->height &&
        current->refreshRate == vm->refreshRate &&
        current->redBits == vm->redBits &&
        current->greenBits == vm->greenBits &&
        current->blueBits == vm->blueBits)
      mode->current = 1;
  }

  return mode;
}
