#ifndef SELEYA_H
#define SELEYA_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>

typedef struct seleya_window_t seleya_window_t;
typedef struct seleya_monitor_t seleya_monitor_t;

#define SELEYA_ENGINE_NAME "libseleya"

seleya_monitor_t *seleya_init(void);
void seleya_loop(seleya_window_t *w);
void seleya_terminate(seleya_monitor_t *m);

#endif
