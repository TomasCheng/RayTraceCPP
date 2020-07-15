#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include "World.h"
#include "Polygon.h"
#include "Ray.h"
#include "Camera.h"

class Screen
{
public:
    int width;
    int height;
    cv::Mat screenImg;

public:
    Screen(/* args */);
    ~Screen();

    void render(World *world,Camera* camera);

private:

    glm::vec3 rayTrace(World* world,Ray ray,int maxDepth);
};
