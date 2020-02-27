///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#include <iostream>

#include <camera.h>
#include <math.h>
#include <IO/KeyBoard.h>
#include <IO/Mouse.h>
#include <IO/Joystick/Joystick.h>

#include <Types.h>
#include <Includes.h>

Camera::Camera(glm::vec3 cPosition, glm::vec3 cOrientation)
{
    this->Orientation = glm::vec3(cOrientation);
    this->Position = glm::vec3(cPosition);
    this->FieldOfView = 65.0f;
    this->MovementSpeed = 0.0f;
    this->MouseSpeed = 0.002f;
    this->JoystickSensibility = 0.05f;
    this->PositionhasChanged = false;
    this->OrientationhasChanged = false;
    this->MaxMovementSpeed = 3.3;
    this->horizontalAngle = 0.0;
    this->verticalAngle = 0.0;
}

void Camera::Update(GLFWwindow *&win)
{
    HandleInputs(win);

    GetExternalInputs();
}

void Camera::GetExternalInputs(void)
{
    if (this->OrientationhasChanged)
    {
        this->Orientation = this->newOrientation;
        this->OrientationhasChanged = false;
    }
    if (this->PositionhasChanged)
    {
        this->Position = this->newPosition;
        this->PositionhasChanged = false;
    }
}

void Camera::LockCamera(void)
{
    auto k = Helpers::getMinimum<double>();
    auto bias = 0.05;

    verticalAngle = Helpers::clamp(verticalAngle, -HPI + bias, HPI - bias);
    horizontalAngle = Helpers::clamp(horizontalAngle, -PI, PI, -k, -1.0);
}

void Camera::HandleInputs(GLFWwindow *&window)
{

    if (glm::isnan(this->Position.x))
        this->Position.x = 0;
    if (glm::isnan(this->Position.y))
        this->Position.y = 0;
    if (glm::isnan(this->Position.z))
        this->Position.z = 0;

    static double LastTime = glfwGetTime();

    double currentTime = glfwGetTime();

    float DeltaTime = float(currentTime - LastTime);

    static double lastX, lastY;

    glfwGetWindowSize(window, &winx, &winy);

    auto _Joystick = Input::Joystick::JoystickManager::PrimaryJoystick();
    
    if (!_Joystick->getJoystickIsPresent())
    {
        horizontalAngle += MouseSpeed * float(lastX - Input::Mouse::XPOS);
        verticalAngle += MouseSpeed * float(lastY - Input::Mouse::YPOS);

        lastX = Input::Mouse::XPOS;
        lastY = Input::Mouse::YPOS;
    }
    else
    {
        if (!Helpers::inRange(_Joystick->R3().x, -0.1f, 0.1f))
            horizontalAngle -= JoystickSensibility * float(_Joystick->R3().x);

        if (!Helpers::inRange(_Joystick->R3().y, -0.1f, 0.1f))
            verticalAngle -= JoystickSensibility * float(_Joystick->R3().y);
    }

    LockCamera();

    Orientation = glm::vec3(
        cos(verticalAngle) * sin(horizontalAngle),
        sin(verticalAngle),
        cos(verticalAngle) * cos(horizontalAngle));

    Rigth = glm::vec3(
        sin(horizontalAngle - HPI),
        0,
        cos(horizontalAngle - HPI));

    Orientation = glm::normalize(Orientation);

    Up = glm::cross(Rigth, Orientation);

    /** Keyboard Camera input**/
    if (!_Joystick->getJoystickIsPresent())
    {
        if (Input::KeyBoard::KEYS[Input::GLFW::Key::W])
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position += Orientation * MovementSpeed * DeltaTime;
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::S])
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position -= Orientation * MovementSpeed * DeltaTime;
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::D])
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position += Rigth * MovementSpeed * DeltaTime;
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::A])
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position -= Rigth * MovementSpeed * DeltaTime;
        }

        if (!Input::KeyBoard::KEYS[Input::GLFW::Key::A] &&
            !Input::KeyBoard::KEYS[Input::GLFW::Key::W] &&
            !Input::KeyBoard::KEYS[Input::GLFW::Key::S] &&
            !Input::KeyBoard::KEYS[Input::GLFW::Key::D])
        {
            MovementSpeed = glm::mix(MovementSpeed, 0.0f, 2.0f * DeltaTime);
        }
    }
    /**---------------------------------------------------------------**/

    /** Joystick Camera input**/
    if (_Joystick->getJoystickIsPresent())
    {
        if (Input::KeyBoard::KEYS[Input::GLFW::Key::W] || _Joystick->L3().y < 0.0)
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position += Orientation * MovementSpeed * DeltaTime * (glm::abs(_Joystick->L3().y * 2));
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::S] || _Joystick->L3().y > 0.0)
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position -= Orientation * MovementSpeed * DeltaTime * (glm::abs(_Joystick->L3().y * 2));
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::D] || _Joystick->L3().x > 0.0)
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position += Rigth * MovementSpeed * DeltaTime * (glm::abs(_Joystick->L3().x * 2));
        }

        if (Input::KeyBoard::KEYS[Input::GLFW::Key::A] || _Joystick->L3().x < 0.0)
        {
            MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 2.0f * DeltaTime);
            Position -= Rigth * MovementSpeed * DeltaTime * (glm::abs(_Joystick->L3().x * 2));
        }

        if (
            _Joystick->L3().x > -0.1 &&
            _Joystick->L3().x < 0.1 &&
            _Joystick->L3().y > -0.1 &&
            _Joystick->L3().y < 0.1)
        {
            MovementSpeed = 0.0f; //glm::mix(MovementSpeed, 0.0f, 2.0f * DeltaTime);
        }
    }
    /** ------------------------------------------------------------------*/

    if (MovementSpeed < 0.05)
        MovementSpeed = 0.0f;

    LastTime = currentTime;

    Position += (MovementVector * MovementSpeed * DeltaTime);
    mIsMoving = false;
    if (LastPosition != Position)
    {
        DeltaVector = (Position - LastPosition);
        MovementVector = glm::normalize(DeltaVector / glm::vec3(glm::sqrt(glm::pow(DeltaVector.x, 2.0) + glm::pow(DeltaVector.y, 2.0) + glm::pow(DeltaVector.z, 2.0))));
        mIsMoving = true;
    }
    if (LastOrientation != Orientation)
        mIsMoving = true;

    LastPosition = Position;
    LastOrientation = Orientation;

    Frustrum = Position + Orientation;
}

void Camera::UpdateMatrices(void)
{
    float Aspectratio;
    Aspectratio = (float)winx / (float)winy;

    ProjectionMatrix = glm::perspective(glm::radians(FieldOfView), glm::max(Aspectratio, 1.0f), 0.1f, 3000.0f);

    PrevView = ViewMatrix;

    ViewMatrix = glm::lookAt(
        Position,
        Position + Orientation,
        glm::vec3(0, 1, 0));
}

glm::mat4 Camera::getViewMatrix(void)
{
    return this->ViewMatrix;
}

glm::mat4 Camera::getProjectionMatrix(void)
{
    return this->ProjectionMatrix;
}

bool Camera::isMoving()
{
    return mIsMoving;
}

glm::vec3 Camera::getPosition(void)
{
    return this->Position;
}

glm::vec3 Camera::getDirection(void)
{
    return this->Orientation;
}

glm::vec3 Camera::getUp(void)
{
    return this->Up;
}
glm::vec3 Camera::getRight(void)
{
    return this->Rigth;
}

void Camera::setPosition(glm::vec3 newPosition)
{
    this->Position = newPosition;
}

void Camera::setDirection(glm::vec3 newDirection)
{
    this->Orientation = newDirection;
}

glm::mat4 Camera::getPrevViewMatrix()
{
    return PrevView;
}

void Camera::setFoV(float FoV)
{
    this->FieldOfView = FoV;
}

float Camera::getFoV()
{
    return this->FieldOfView;
}

void Camera::setProjection(float FOV, float AR, float NEAR, float FAR)
{
    this->ProjectionMatrix = glm::perspective(glm::radians(FOV), AR, NEAR, FAR);
}

void Camera::setProjection(glm::mat4 newProj)
{
    this->ProjectionMatrix = newProj;
}

void Camera::setViewMatrix(glm::mat4 newView)
{
    this->ViewMatrix = newView;
}
