#pragma once

#include <glm/glm.hpp>

class Ray
{
public:
    glm::vec3 origin;

    glm::vec3 direction;

    glm::vec3 color;

    float intensity;

public:
    Ray(glm::vec3 _oringin, glm::vec3 _direction, glm::vec3 _color, float _intensity) : origin(_oringin),
                                                                                         direction(_direction), color(_color), intensity(_intensity) {}

    Ray(){}

    ~Ray();

    glm::vec3 GetEndPoint(float distance);
};

class IntersectResult
{
public:
    void *polygon = nullptr;

    glm::vec3 position;

    float distance;

    glm::vec3 normal;

    glm::vec3 reflect;
};
