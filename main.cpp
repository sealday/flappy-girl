#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "shader.h"
#include "shader_string.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);


int main() {

    glfwInit();


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "flappy girl", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // set callback
    glfwSetKeyCallback(window, key_callback);

    gladLoadGL();

    // init opengl
    glClearColor(0.3f, 0.4f, 0.5f, 1.0f);

    GLuint vao, vbo;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);


    // init program
    GLint program = createProgram(vert::shader, frag::shader);
    glUseProgram(program);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);


        glBindVertexArray(vao);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
