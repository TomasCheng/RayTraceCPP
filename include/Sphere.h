#pragma once

#include <glm/glm.hpp>
#include "Polygon.h"
#include "Ray.h"

class Sphere : public Polygon
{
public:
    glm::vec3 center;

    float radius;

public:
    Sphere(glm::vec3 _center,float _radius):center(_center),radius(_radius){}

    Sphere(){Sphere(glm::vec3(0),1);};

    ~Sphere();

    glm::vec3 getNormal(glm::vec3 _vec);

    bool intersect(Ray ray,IntersectResult &result);
};

