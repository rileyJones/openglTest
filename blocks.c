#include "common.h"

#define SHADER_COUNT 2

int main() {
    
    GLFWwindow *window = init();    
        
    GLuint shaders[SHADER_COUNT];
    shaders[0] = compileShader("shaders/vertCube.shader", GL_VERTEX_SHADER);
    shaders[1] = compileShader("shaders/fragCube.shader", GL_FRAGMENT_SHADER);
    GLuint shaderProgram = createProgram(shaders, SHADER_COUNT);
        


    static const GLfloat vertices_position[] = {
		-0.25f, -0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,
		-0.25f, -0.25f,  0.25f,
		
		-0.25f,  0.25f,  0.25f,
		-0.25f, -0.25f,  0.25f,
		-0.25f,  0.25f, -0.25f,
		
		
		-0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f,  0.25f,
		 0.25f, -0.25f, -0.25f,
		
		 0.25f, -0.25f,  0.25f,
		 0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f,  0.25f,
		
		
		-0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,
		
		 0.25f,  0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		
		
		
		 0.25f,  0.25f,  0.25f,
		 0.25f,  0.25f, -0.25f,
		 0.25f, -0.25f,  0.25f,
		
		 0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f,  0.25f,
		 0.25f,  0.25f, -0.25f,
		
		
		 0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		 0.25f,  0.25f, -0.25f,
		
		-0.25f,  0.25f, -0.25f,
		 0.25f,  0.25f, -0.25f,
		-0.25f,  0.25f,  0.25f,
		
		
		 0.25f,  0.25f,  0.25f,
		 0.25f, -0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		
		-0.25f, -0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		 0.25f, -0.25f,  0.25f,
		
	};



    GLuint buffer;
    GLuint vao;
    
    glCreateVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &buffer);

    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_position), vertices_position, GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    
    
    
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glVertexAttribI1i(1, 45);
        glVertexAttrib1f(2, glfwGetTime());
        glVertexAttrib1f(3, 0);
        glVertexAttrib1f(4, 0.5);
        
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    
    close(window);
}
