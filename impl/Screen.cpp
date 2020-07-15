#include <opencv2/opencv.hpp>
#include "Screen.h"
#include "util.h"
#include "Ray.h"

Screen::Screen(/* args */)
{
    width = 512;
    height = 512;

    screenImg= cv::Mat::zeros(cv::Size( width, height),CV_8UC3);
}

Screen::~Screen()
{
}

void Screen::render(World *world, Camera *camera)
{
    if (world == nullptr || camera == nullptr)
    {
        std::cout << "error" << std::endl;
        return;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sy = 1 - i * 1.0f / height;
            float sx = j * 1.0f / width;
            Ray ray = camera->generateRay(sx, sy);

            glm::vec3 color = rayTrace(world, ray, world->maxReflectDepth);

            color.x = util::clamp<float>(color.x, 0, 255);
            color.y = util::clamp<float>(color.y, 0, 255);
            color.z = util::clamp<float>(color.z, 0, 255);

            screenImg.at<cv::Vec3b>(i, j) = cv::Vec3b(color.x, color.y, color.z);
        }
    }
}

glm::vec3 Screen::rayTrace(World* world, Ray ray, int maxDepth)
{
    IntersectResult res = world->interset(ray);

    if(res.polygon)
    {
        glm::vec3 color = glm::vec3(1);

        if(maxDepth > 0)
        {
            Ray ray2;
            ray2.origin = res.position;
            ray2.direction = res.reflect;

            glm::vec3 r = rayTrace(world,ray2,maxDepth - 1);

            // std::cout<<"111111"<<std::endl;
            color = color + r;
        }
        return color;
    }
    else
    {
        // std::cout<<"3333333"<<std::endl;

        return glm::vec3(0);
    }
}