#pragma once

namespace Input
{
    class Mouse
    {
    public:
        static double XPOS;
        static double YPOS;

        static void MouseCallBackGLFW(GLFWwindow* window, double xpos, double ypos)
        {
            XPOS = xpos;
            YPOS = ypos;
        }
    };

}
