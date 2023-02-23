#ifndef MINECRAFT_WINDOW_H
#define MINECRAFT_WINDOW_H

#define GLFW_INCLUDE_NONE
#define GL_GLEXT_PROTOTYPES

#include <GLFW/glfw3.h>

#include "glad/glad.h"

GLFWwindow* createWindow(uint32_t w, uint32_t h, const char* title);

void framebufferSizeCallback(GLFWwindow* window, int w, int h);

#endif
