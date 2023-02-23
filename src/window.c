#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/minecraft.h"

void framebufferSizeCallback(GLFWwindow* window, int w, int h) {
  glViewport(0, 0, w, h);
}


GLFWwindow* createWindow(uint32_t w, uint32_t h, const char* title) {
  GLFWwindow* window = glfwCreateWindow(w, h, title, NULL, NULL);
	
  if (!window) {
    fprintf(stderr, "Failed to create GLFW\n");
    glfwTerminate();

    return NULL;
  }

  glfwMakeContextCurrent(window);
	
	// Callback for resizing window
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback); 

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    fprintf(stderr, "Failed to initialize GLAD\n");

		glfwTerminate();
		exit(EXIT_FAILURE);
  }

  glViewport(0, 0, w, h);

  return window;
}

