#include "Camera.h"

void Umbrella::Camera::SetPosition(glm::vec3 position)
{
}

glm::vec3 Umbrella::Camera::GetPosition()
{
    return {0, 0, 0};
}

void Umbrella::Camera::SetRotation(glm::vec3 rotation)
{
}

glm::vec3 Umbrella::Camera::GetRotation()
{
    return {0, 0, 0};
}

void Umbrella::Camera::SetScale(glm::vec3 scale)
{
}

glm::vec3 Umbrella::Camera::GetScale()
{
    return {0, 0, 0};
}

void Umbrella::Camera::SetSize(glm::ivec2 size)
{
}

glm::ivec2 Umbrella::Camera::GetSize()
{
    return {0, 0};
}

glm::mat4 Umbrella::Camera::GetCameraMatrix()
{
    return glm::mat4(0);
}
