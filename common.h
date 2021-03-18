#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


GLFWwindow* init();
void close(GLFWwindow *window);

GLuint compileShader(const char *shader_path, GLenum shaderType);
GLuint createProgram(GLuint *shaders, int shaderCount); 

#endif
