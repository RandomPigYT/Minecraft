#ifndef MINECRAFT_H
#define MINECRAFT_H

#define GL_GLEXT_PROTOTYPES
#define GLFW_INCLUDE_NONE

#include "window.h"

#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include <stdbool.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

void init(uint8_t majorVersion, uint8_t minorVersion);

uint32_t initShader(const char *vertexPath, const char *fragmentPath);
void useShader(uint32_t id);

void setBool(uint32_t id, const char *uniformName, bool value);
void setInt(uint32_t id, const char *uniformName, int value);
void setFloat(uint32_t id, const char *uniformName, float value);

#endif
