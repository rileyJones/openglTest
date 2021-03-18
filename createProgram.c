#include "common.h"


// GL_COMPUTE_SHADER
// GL_VERTEX_SHADER
// GL_TESS_CONTROL_SHADER
// GL_TESS_EVALUATION_SHADER
// GL_GEOMETRY_SHADER
// GL_FRAGMENT_SHADER
GLuint compileShader(const char *shader_path, GLenum shaderType) {
    // https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c
    FILE *shaderFile = fopen(shader_path, "r");
    long lSize;
    char *src;
    
    if(!shaderFile) {
        printf("Shader file: \"%s\" does not exist or could not be read", shader_path);
        return -1;
    }
    fseek(shaderFile, 0L, SEEK_END);
    lSize = ftell(shaderFile);
    rewind(shaderFile);

    src = (char*)calloc(1, lSize + 1);
    if(!src) {
        fclose(shaderFile);
        printf("Memory alloc failed.");
        return -1;
    }
    if(1 != fread(src, lSize, 1, shaderFile)) {
        fclose(shaderFile);
        free(src);
        printf("Memory read fails.");
        return -1;
    }

    fclose(shaderFile);

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    GLint test;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &test);
    if(!test) {
        char *compLog = (char*)calloc(512, sizeof(char));
        glGetShaderInfoLog(shader, 511 * sizeof(char), NULL, compLog);
        printf("Shader compilation failed with message: %s", compLog);
        free(compLog);
        free(src);
        return -1;
    }
    free(src);
    return shader;
}

GLuint createProgram(GLuint *shaders, int shaderCount) {
    GLuint shaderProgram = glCreateProgram();
    for(int i = 0; i < shaderCount; i++) {
        glAttachShader(shaderProgram, shaders[i]);
        glDeleteShader(shaders[i]);
    }
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    return shaderProgram;
}


