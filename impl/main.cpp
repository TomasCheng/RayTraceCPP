#include <opencv2/opencv.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>

#include "Ray.h"
#include "Sphere.h"
#include "Polygon.h"
#include "World.h"
#include "Screen.h"


Screen* globalScreen;
World* globalWorld;
Camera* globalCamera;

int main(int argc, char **argv)
{
    std::cout<<"rayRace start..."<<std::endl;

    globalScreen = new Screen();

    globalCamera = new Camera(glm::vec3(0,-10,10),glm::vec3(0,1,0),glm::vec3(0,0,1),120);

    globalWorld = new World();

    Sphere* sp = new Sphere();
    globalWorld->polygons.push_back(sp);

    globalScreen->render(globalWorld,globalCamera);
    
    cv::imshow("rayTrace screen",globalScreen->screenImg);

    cv::waitKey(0);
    
    return 0;
}
