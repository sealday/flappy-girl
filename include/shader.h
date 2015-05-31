#include <glad/glad.h>

#include <iostream>


GLint createProgram(const char *vShaderCode, const char *fShaderCode) {

    GLint program = glCreateProgram();
    GLint vShader = glCreateShader(GL_VERTEX_SHADER);
    GLint fShader = glCreateShader(GL_FRAGMENT_SHADER);


    GLint success;
    GLchar infoLog[512];
    glShaderSource(vShader, 1, &vShaderCode, NULL);
    glShaderSource(fShader, 1, &fShaderCode, NULL);

    glCompileShader(vShader);
    glCompileShader(fShader);

    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vShader, 1, NULL, infoLog);
        std::cerr << infoLog << std::endl;
        exit(-1);
    }

    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fShader, 1, NULL, infoLog);
        std::cerr << infoLog << std::endl;
        exit(-1);
    }

    glAttachShader(program, vShader);
    glAttachShader(program, fShader);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program, 1, NULL, infoLog);
        std::cerr << infoLog << std::endl;
        exit(-1);
    }

    glDeleteShader(vShader);
    glDeleteShader(fShader);

    return program;
}

