#pragma once

#include <vector>
#include "Polygon.h"
#include "Ray.h"

class World
{
public:

    int maxReflectDepth;
    std::vector<Polygon *> polygons;

public:
    World(/* args */);
    ~World();

    IntersectResult interset(Ray ray);

};


