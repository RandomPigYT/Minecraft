#include "../include/minecraft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  


int main(int argc, char** argv) {
  init(4, 5);

  GLFWwindow* window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Minecraft");

	uint32_t vbo, vao;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	uint32_t program = initShader("shaders/vertexShader.vert", "shaders/fragShader.frag");
	

  while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	
		
		useShader(program);
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

	glfwTerminate();
}
