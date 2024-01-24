#ifndef blender_hpp
#define blender_hpp

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;


class Blender {
    
    static int ctr;
    static Blender* blenderInstance;

    Blender();
    Blender(const Blender &obj);
    Blender operator=(const Blender &obj);

    public :

        Mat input(const char* str);
        void display(const char* str, Mat image);
        Mat alpha_blender(Mat image1, Mat image2, double alpha, const char* str);

        static Blender* getBlenderInstance();

};



#endif