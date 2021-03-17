#include "common.h"

int main() {
    

    GLFWwindow *window = init();    

    while(!glfwWindowShouldClose(window)) {
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    close(window);
}
