#include "Camera.h"

Camera::Camera(glm::vec3 _position, glm::vec3 _front, glm::vec3 _up, float fov)
{
    position = _position;

    front = glm::normalize(_front);

    right = glm::normalize(glm::cross(front, _up));

    up = glm::normalize(glm::cross(right, front));

    scale = glm::tan(glm::radians(fov * 0.5)) * 2;
}

Camera::~Camera()
{
}

Ray Camera::generateRay(float x, float y)
{
    glm::vec3 u = right * glm::vec1(x -0.5) * glm::vec1(scale);
    glm::vec3 v = up * glm::vec1(y -0.5) * glm::vec1(scale);

    glm::vec3 dir = front + u + v;

    Ray r = Ray(position,dir,glm::vec3(0),0);

    return r;
}