#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

void Umbrella::Camera::SetPosition(glm::vec3 position)
{
    _position = position;
}

glm::vec3 Umbrella::Camera::GetPosition()
{
    return _position;
}

void Umbrella::Camera::SetRotation(glm::vec3 rotation)
{
    _rotation = rotation;
}

glm::vec3 Umbrella::Camera::GetRotation()
{
    return _rotation;
}

void Umbrella::Camera::SetScale(glm::vec3 scale)
{
    _scale = scale;
}

glm::vec3 Umbrella::Camera::GetScale()
{
    return _scale;
}

void Umbrella::Camera::SetSize(glm::ivec2 size)
{
    _size = size;
}

glm::ivec2 Umbrella::Camera::GetSize()
{
    return _size;
}

glm::mat4 Umbrella::Camera::GetCameraMatrix()
{
    glm::mat4 view = {};
    view = glm::translate(view, GetPosition());
    view = glm::rotate(view, GetRotation().x, glm::vec3(1, 0, 0));
    view = glm::rotate(view, GetRotation().y, glm::vec3(0, 1, 0));
    view = glm::rotate(view, GetRotation().z, glm::vec3(0, 0, 1));
    view = glm::scale(view, GetScale());
    return view;
}
