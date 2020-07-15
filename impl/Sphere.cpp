#include "Sphere.h"

Sphere::~Sphere()
{
}

glm::vec3 Sphere::getNormal(glm::vec3 _vec)
{
    return _vec - center;
}

bool Sphere::intersect(Ray ray,IntersectResult &result)
{
    glm::vec3 v = ray.origin - center ;

    float a0 = v.length() * v.length() - radius * radius;

    float DdotV = glm::dot(ray.direction,v);

    if(DdotV <= 0)
    {
        float discr = DdotV*DdotV - a0;
        if(discr >=0)
        {
            result.polygon = this;
            result.distance = DdotV - glm::sqrt(discr);
            result.position = ray.GetEndPoint(result.distance);
            result.normal = glm::normalize(result.position - center);

            result.reflect = ray.direction - 2 * (glm::dot(ray.direction,result.normal))*result.normal;
            
            return true;
        }
    }

    return false;
}
