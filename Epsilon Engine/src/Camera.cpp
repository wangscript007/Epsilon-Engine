///========= Copyright Survtech, All rights reserved. ============//
///
/// Purpose:
///
///=============================================================================

#include <iostream>

#include <camera.h>
#include <math.h>
float lerp(float v0, float v1, float t)
{
    return (1-t)*v0 + t*v1;
}

Camera::Camera(glm::vec3 cPosition, glm::vec3 cOrientation)
{
    this->Orientation = glm::vec3(cOrientation);
    this->Position = glm::vec3(cPosition);
    this->FieldOfView = 75.5f;
    this->MovementSpeed = 0.0f;
    this->MouseSpeed = 0.005f;
    this->PositionhasChanged = false;
    this->OrientationhasChanged = false;
    this->MaxMovementSpeed = 15.3;
    this->horizontalAngle = 0.0;
    this->verticalAngle = 0.0;
    this->LastPosition;
}

void Camera::Update(GLFWwindow* win)
{
    window = win;

    HandleInputs();

    GetExternalInputs();
}

void Camera::GetExternalInputs(void)
{
    if(this->OrientationhasChanged)
    {
        this->Orientation = this->newOrientation;
        this->OrientationhasChanged = false;
    }
    if(this->PositionhasChanged)
    {
        this->Position = this->newPosition;
        this->PositionhasChanged = false;
    }
}

void Camera::LockCamera(void)
{
    if(verticalAngle > 1.4208)
        verticalAngle = 1.4208;

    if(verticalAngle < -1.4508)
        verticalAngle = -1.4508;

    if(horizontalAngle < -3.1416)
        horizontalAngle = 3.1414;

    if(horizontalAngle>3.1416)
        horizontalAngle = -3.1414;

}

void Camera::HandleInputs(void)
{

    if(glm::isnan(this->Position.x))
        this->Position.x = 0;
    if(glm::isnan(this->Position.y))
        this->Position.y = 0;
    if(glm::isnan(this->Position.z))
        this->Position.z = 0;

    static double LastTime = glfwGetTime();

    double currentTime = glfwGetTime();

    float DeltaTime = float( currentTime - LastTime );

    double xpos, ypos;

    glfwGetWindowSize(window , &winx , &winy );
    glfwGetCursorPos(window, &xpos , &ypos );
    glfwSetCursorPos(window, winx/2.0, winy/2.0);


    horizontalAngle += MouseSpeed * float( winx/2.0 - xpos ) ;
    verticalAngle   += MouseSpeed * float( winy/2.0 - ypos ) ;

    Orientation = glm::vec3(
                      cos( verticalAngle )      *       sin( horizontalAngle ),
                      sin( verticalAngle ),
                      cos( verticalAngle )      *       cos( horizontalAngle )
                  );

    Rigth = glm::vec3(
                sin(horizontalAngle     -       3.14f/2.0f),
                0,
                cos(horizontalAngle     -       3.14f/2.0f)
            );

    LockCamera();

    Up = glm::cross( Rigth , Orientation );


    if ( glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS )
    {
        MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 1.5f * DeltaTime);
        Position += Orientation   *     MovementSpeed      *   DeltaTime;
    }

    if ( glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS )
    {
        MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 1.5f * DeltaTime);
        Position -= Orientation   *     MovementSpeed      *   DeltaTime;
    }

    if ( glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS )
    {
        MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 1.5f * DeltaTime);
        Position += Rigth       *     MovementSpeed      *   DeltaTime;
    }

    if ( glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS )
    {
        MovementSpeed = glm::mix(MovementSpeed, this->MaxMovementSpeed, 1.5f * DeltaTime);
        Position -= Rigth       *     MovementSpeed      *   DeltaTime;
    }

    if ( glfwGetKey( window, GLFW_KEY_A ) != GLFW_PRESS && glfwGetKey( window, GLFW_KEY_W ) != GLFW_PRESS && glfwGetKey( window, GLFW_KEY_S ) != GLFW_PRESS && glfwGetKey( window, GLFW_KEY_D ) != GLFW_PRESS )
    {
        MovementSpeed = glm::mix(MovementSpeed, 0.0f, 1.5f * DeltaTime);

    }

    LastTime = currentTime;

    Position += (MovementVector * MovementSpeed * DeltaTime);
    if(LastPosition != Position)
    {
        DeltaVector = (Position - LastPosition);
        MovementVector = glm::normalize(DeltaVector / glm::vec3( glm::sqrt(glm::pow(DeltaVector.x, 2.0)  + glm::pow(DeltaVector.y, 2.0) + glm::pow(DeltaVector.z , 2.0) ) ));
    }

    Orientation = Orientation;


    LastPosition = Position;

    Frustrum = Position+Orientation;
}

void Camera::UpdateMatrices(void)
{


    float Aspectratio;
    Aspectratio = (float)winx/(float)winy;

    if ( Aspectratio < 1.5 )
    {
        ProjectionMatrix = glm::perspective( glm::radians(FieldOfView) , 4.0f/ 3.0f , 0.1f , 3000.0f );
    }
    else if( Aspectratio > 1.7 )
    {
        ProjectionMatrix = glm::perspective( glm::radians(FieldOfView) , 16.0f/ 9.0f , 0.1f , 3000.0f );
    }
    else
    {
        ProjectionMatrix = glm::perspective( glm::radians(FieldOfView) , 16.0f/ 10.0f , 0.1f , 3000.0f );
    }

    ViewMatrix       = glm::lookAt(
                           Position,
                           Position+Orientation,
                           glm::vec3(0,1,0)
                       );
    glm::mat4 Model = glm::mat4();

}

glm::mat4 Camera::getViewMatrix(void)
{
    return this->ViewMatrix;
}

glm::mat4 Camera::getProjectionMatrix(void)
{
    return this->ProjectionMatrix;
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

glm::vec3 Camera::setPosition(glm::vec3 newPosition)
{
    this->Position = newPosition;
}

glm::vec3 Camera::setDirection(glm::vec3 newDirection)
{
    this->Orientation = newDirection;
}
