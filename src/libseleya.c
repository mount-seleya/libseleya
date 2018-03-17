#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

GLFWwindow *seleya_create_window(int w, int h, char *title)
{
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  return glfwCreateWindow(w, h, title, NULL, NULL);
}

void seleya_init()
{
  glfwInit();
}
