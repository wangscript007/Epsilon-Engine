#pragma once

#define 	GLFW_GAMEPAD_BUTTON_A   0
#define 	GLFW_GAMEPAD_BUTTON_B   1
#define 	GLFW_GAMEPAD_BUTTON_X   2
#define 	GLFW_GAMEPAD_BUTTON_Y   3
#define 	GLFW_GAMEPAD_BUTTON_LEFT_BUMPER   4
#define 	GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER   5
#define 	GLFW_GAMEPAD_BUTTON_BACK   6
#define 	GLFW_GAMEPAD_BUTTON_START   7
#define 	GLFW_GAMEPAD_BUTTON_GUIDE   8
#define 	GLFW_GAMEPAD_BUTTON_LEFT_THUMB   9
#define 	GLFW_GAMEPAD_BUTTON_RIGHT_THUMB   10
#define 	GLFW_GAMEPAD_BUTTON_DPAD_UP   11
#define 	GLFW_GAMEPAD_BUTTON_DPAD_RIGHT   12
#define 	GLFW_GAMEPAD_BUTTON_DPAD_DOWN   13
#define 	GLFW_GAMEPAD_BUTTON_DPAD_LEFT   14
#define 	GLFW_GAMEPAD_BUTTON_LAST   GLFW_GAMEPAD_BUTTON_DPAD_LEFT
#define 	GLFW_GAMEPAD_BUTTON_CROSS   GLFW_GAMEPAD_BUTTON_A
#define 	GLFW_GAMEPAD_BUTTON_CIRCLE   GLFW_GAMEPAD_BUTTON_B
#define 	GLFW_GAMEPAD_BUTTON_SQUARE   GLFW_GAMEPAD_BUTTON_X
#define 	GLFW_GAMEPAD_BUTTON_TRIANGLE   GLFW_GAMEPAD_BUTTON_Y


namespace Input
{
    namespace GLFW
    {
        namespace Joystick
        {

            static constexpr int A = GLFW_GAMEPAD_BUTTON_A;
            static constexpr int B = GLFW_GAMEPAD_BUTTON_B;
            static constexpr int X = GLFW_GAMEPAD_BUTTON_X;
            static constexpr int Y = GLFW_GAMEPAD_BUTTON_Y;
            static constexpr int LEFT_BUMPER = GLFW_GAMEPAD_BUTTON_LEFT_BUMPER;
            static constexpr int RIGHT_BUMPER = GLFW_GAMEPAD_BUTTON_RIGHT_BUMPER;
            static constexpr int BACK = GLFW_GAMEPAD_BUTTON_BACK;
            static constexpr int START = GLFW_GAMEPAD_BUTTON_START;
            static constexpr int GUIDE = GLFW_GAMEPAD_BUTTON_GUIDE;
            static constexpr int LEFT_THUMB = GLFW_GAMEPAD_BUTTON_LEFT_THUMB;

            static constexpr int RIGHT_THUMB = GLFW_GAMEPAD_BUTTON_RIGHT_THUMB;
            static constexpr int UP = GLFW_GAMEPAD_BUTTON_DPAD_UP;
            static constexpr int RIGHT = GLFW_GAMEPAD_BUTTON_DPAD_RIGHT;
            static constexpr int DOWN = GLFW_GAMEPAD_BUTTON_DPAD_DOWN;
            static constexpr int LEFT = GLFW_GAMEPAD_BUTTON_DPAD_LEFT;
            static constexpr int CROSS = GLFW_GAMEPAD_BUTTON_A;
            static constexpr int CIRCLE = GLFW_GAMEPAD_BUTTON_B;
            static constexpr int SQUARE = GLFW_GAMEPAD_BUTTON_X;
            static constexpr int TRIANGLE = GLFW_GAMEPAD_BUTTON_Y;

        }
    }
}

