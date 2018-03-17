#ifndef SELEYA_H
#define SELEYA_H

#ifndef GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif
#include <GLFW/glfw3.h>

GLFWwindow *seleya_create_window(int w, int h, char *title);
void seleya_init();

#endif
