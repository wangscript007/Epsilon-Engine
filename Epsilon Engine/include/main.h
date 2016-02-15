///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <ProgramData.h>
#include <Epsilon.h>

class App
{
public:

    App(GLFWwindow* win)
    {
        EpsilonEngine = new Epsilon(win);

        EpsilonEngine->InitResources();
    }

    void Run(void)
    {
        std::cout << "==================================================" << std::endl;
        std::cout << "Engine Initialization Complete." << std::endl;
        std::cout << "Now Rendering." << std::endl;

        EpsilonEngine->MainLoop();
    }

    virtual ~App(void) {
        delete EpsilonEngine;
    }

public:
    Epsilon* EpsilonEngine;

};

GLFWwindow* InitEngine(const char* ProgramName)
{
    std::cout << "Initializing Epsilon Engine" << std::endl;

    ProgramData DATA;

    if(!glfwInit())
    {
        std::cout << "GLFW could not be initialized" << std::endl;
    }

    /// glfwWindowHint(GLFW_SAMPLES, DATA.MSAA_SAMPLES);

    int numberofmonitors;

    GLFWmonitor** Monitor;
    GLFWmonitor* CurrentMonitor;

    Monitor = glfwGetMonitors(&numberofmonitors);

    if(numberofmonitors < DATA.MONITOR)
        CurrentMonitor = Monitor[0];
    else
    CurrentMonitor = Monitor[DATA.MONITOR];

    int numberofmodes;

    const GLFWvidmode* modes = glfwGetVideoModes(CurrentMonitor, &numberofmodes);

    GLFWwindow* window;

    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    cout << "Creating window || Window Resolution: ";
    if(DATA.FULLSCREEN)
    {
        window = glfwCreateWindow(DATA.WINDOW_WIDTH, DATA.WINDOW_HEIGHT, ProgramName, glfwGetPrimaryMonitor(), 0);
        cout << DATA.WINDOW_WIDTH << " x " << DATA.WINDOW_HEIGHT << endl;
    }
    else
    {
        window = glfwCreateWindow(DATA.WINDOW_WIDTH, DATA.WINDOW_HEIGHT, ProgramName, 0, 0);
        cout << DATA.WINDOW_WIDTH << " x " << DATA.WINDOW_HEIGHT << endl;
    }

    glfwMakeContextCurrent(window);

    if(!window)
    {
        std::cout << "Window could not be created" << std::endl;
    }

    glfwSetWindowPos(window, modes->width/2, modes->height/2);

    glewExperimental = GL_TRUE;
    glewInit();

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwSwapInterval(DATA.VSYNC);

    delete Monitor;
    delete CurrentMonitor;
    delete modes;

    return window;
}

#endif /// MAIN_H_INCLUDED
