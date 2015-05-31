#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);


int main() {

    glfwInit();


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "flappy girl", NULL, NULL);
    glfwMakeContextCurrent(window);

    // set callback
    glfwSetKeyCallback(window, key_callback);

    gladLoadGL();


    // init opengl
    glClearColor(0.3f, 0.4f, 0.5f, 1.0f);

    GLuint vao;
    glGenVertexArrays(1, &vao);


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);


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
