#pragma once

#include <glm/glm.hpp>
#include "Material.h"
#include "Ray.h"


class Polygon
{
public:
    glm::vec3 position;

    glm::mat3 transform;

    Material* material;

private:
    /* data */
public:
    Polygon(/* args */);
    ~Polygon();

    virtual bool intersect(Ray ray,IntersectResult &result){return false;}
};


