#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define LOG(x) std::cout << x << std::endl;


int main()
{
    

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    //sets OpenGL version to 3.3 for maximum compatibility
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        LOG("Failed to create GLFW Window");
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);


    if (glewInit() != GLEW_OK)
    {
        LOG("error. couldn't initialize GLEW.");
    }
    LOG(glGetString(GL_VERSION));



    glViewport(0,0,200,200);

    glClearColor(0.07f,0.13f,0.17f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}