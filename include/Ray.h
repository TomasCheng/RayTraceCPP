#pragma once

#include <glm/glm.hpp>

class Ray
{
public:

    glm::vec3 position;

    glm::vec3 direction;

    glm::vec3 color;

    float intensity;

public:
    Ray(glm::vec3 _position,glm::vec3 _direction, glm::vec3 _color,float _intensity):position(_position),
    direction(_direction),color(_color),intensity(_intensity){}

    ~Ray();

    glm::vec3 GetEndPoint(float distance);
};


