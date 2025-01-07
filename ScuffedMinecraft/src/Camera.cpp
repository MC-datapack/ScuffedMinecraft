#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Position(position), WorldUp(up), Yaw(yaw), Pitch(pitch), Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
    : Position(glm::vec3(posX, posY, posZ)), WorldUp(glm::vec3(upX, upY, upZ)), Yaw(yaw), Pitch(pitch), Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}

// GetViewMatrix method definition
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;

    if (direction == FORWARD)
    {
        glm::vec3 moveDir = Front;
        moveDir.y = 0;
        moveDir = glm::normalize(moveDir);
        Position += moveDir * velocity;
    }
    if (direction == BACKWARD)
    {
        glm::vec3 moveDir = Front;
        moveDir.y = 0;
        moveDir = glm::normalize(moveDir);
        Position -= moveDir * velocity;
    }
    if (direction == LEFT)
    {
        glm::vec3 moveDir = Front;
        moveDir.y = 0;
        moveDir = glm::normalize(moveDir);
        Position -= glm::normalize(glm::cross(moveDir, Up)) * velocity;
    }
    if (direction == RIGHT)
    {
        glm::vec3 moveDir = Front;
        moveDir.y = 0;
        moveDir = glm::normalize(moveDir);
        Position += glm::normalize(glm::cross(moveDir, Up)) * velocity;
    }
    if (direction == UP)
        Position += glm::vec3(0, 1, 0) * velocity;
    if (direction == DOWN)
        Position -= glm::vec3(0, 1, 0) * velocity;
}

void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}


// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
    MovementSpeed += (float)yoffset;
    if (MovementSpeed < 0)
        MovementSpeed = 0;
    if (MovementSpeed > MaxMovementSpeed)
        MovementSpeed = MaxMovementSpeed;
}