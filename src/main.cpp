#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void) {
    // Init glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Error while creating window.\n" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    // Change background color
    glViewport(0, 0, 800, 800);
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    // Handle window
    while (glfwWindowShouldClose(window) == 0) {
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}