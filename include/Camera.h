#pragma once

#include <glm/glm.hpp>
#include "Ray.h"

class Camera
{
public:
    glm::vec3 position;

    glm::vec3 front;

    glm::vec3 up;

    glm::vec3 right;

    float scale;

    float fov;

    
public:
    Camera(glm::vec3 _position,glm::vec3 _front,glm::vec3 _up,float fov);

    ~Camera();

    Ray generateRay(float x,float y);
};


