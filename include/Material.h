#pragma once

#include <glm/glm.hpp>


class Material
{
public:
    glm::vec3 color = glm::vec3(1);

    float diffuse;

    float specular;

    float transparent;

    float refract;

public:
    Material(/* args */);
    ~Material();

    virtual glm::vec3 Sample(float x,float y){return glm::vec3(0);};
};


