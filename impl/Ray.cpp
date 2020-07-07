#include "Ray.h"

Ray::~Ray()
{
}

glm::vec3 Ray::GetEndPoint(float distance)
{
    return position + direction * distance;
}