#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/blender.hpp"


using namespace cv;


int main() {

    double alpha;
    std::cout << "Enter the alpha value : ";
    std::cin >> alpha;

    Blender* obj = Blender::getBlenderInstance();

    Mat image1 = obj->input("./images/image1.jpeg");
    obj->display("image1", image1);
    
    Mat image2 = obj->input("./images/image2.jpeg");
    obj->display("image2", image2);

    Mat result = obj->alpha_blender(image1, image2, alpha, "./result/blended_image1.jpeg");
    obj->display("Blended_Image", result);

    destroyAllWindows();


    Blender* obj2 = Blender::getBlenderInstance();

    Mat image3 = obj2->input("./images/image3.jpeg");
    obj->display("image1", image3);
    
    Mat image4 = obj2->input("./images/image4.jpeg");
    obj->display("image2", image4);

    Mat result2 = obj2->alpha_blender(image3, image4, alpha, "./result/blended_image2.jpeg");
    obj->display("Blended_Image", result2);

    destroyAllWindows();



    return 0;
}