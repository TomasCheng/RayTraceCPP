#include <iostream>
#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>

int main(int argc, char **argv)
{
    glm::vec3 v(1, 2, 3);

    glm::mat3 m(v, v, v);

    v = glm::normalize(v);

    cv::Mat n = cv::Mat::zeros(300, 300, CV_8UC3);

    for (int i = 0; i < n.cols; i++)
    {
        n.at<uchar>(i, 100) = 255;
    }
    cv::imshow("out", n);
    

    cv::Mat image;
    image = cv::imread("../test.jpg", 1);
    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);

    std::cout << image.rows << "," << image.cols << std::endl;

    cv::imshow("Display Image", image);

    cv::waitKey(0);
    return 0;
}
