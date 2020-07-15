#include "World.h"

World::World(/* args */)
{
    polygons = std::vector<Polygon *>();

    maxReflectDepth = 3;
}

World::~World()
{
}

IntersectResult World::interset(Ray ray)
{
    IntersectResult res;

    for(auto po : polygons)
    {
        IntersectResult tempRes;
        if(po->intersect(ray,tempRes))
        {
            if(tempRes.polygon && tempRes.distance < res.distance)
            {
                res = tempRes;
            }
        }
    }
    return res;
}