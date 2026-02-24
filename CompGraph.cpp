#include <stdio.h>
#include <stdlib.h>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main() {
    GLFWwindow* window;


    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(512, 512, "Mainwindow", NULL, NULL);

    if (!window) {
        fprintf(stderr, "ERROR: could not create window.\n");
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(ret));
        return 1;
    }

    const GLubyte* version_str = glGetString(GL_VERSION);
    const GLubyte* device_str = glGetString(GL_RENDERER);

    printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("This version OpenGL running is %s\n", version_str);
    printf("This device OpenGL running is %s\n", device_str);

    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);


    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);

        glColor3f(0.2, 1.0, 1.0);
        glVertex2f(-0.5f, 0.5f);     

        glColor3f(0.2, 1.0, 1.0);
        glVertex2f(0.5f, 0.5f);    


        glColor3f(0.2, 1.0, 1.0);
        glVertex2f(0.5f, -0.5f);  

        glColor3f(0.2, 1.0, 1.0);
        glVertex2f(-0.5f, -0.5f);

        glEnd();


        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}