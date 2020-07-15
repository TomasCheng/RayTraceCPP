#include "Ray.h"

Ray::~Ray()
{
}

glm::vec3 Ray::GetEndPoint(float distance)
{
    return origin + direction * distance;
}