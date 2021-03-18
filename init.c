#include "common.h"
#define WIDTH 640
#define HEIGHT 480

GLFWwindow* init() {
    GLFWwindow *window;
    if(!glfwInit()) {
        printf("glfw failed to init");
        exit(-1);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(WIDTH, HEIGHT, "testName", NULL, NULL);
    

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("glad failed to init");
        exit(-1);
    }

    
    glViewport(0, 0, HEIGHT, HEIGHT); 
    return window;
}

void close(GLFWwindow *window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

