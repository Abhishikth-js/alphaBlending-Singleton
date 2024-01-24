#include "../include/blender.hpp"


int Blender::ctr = 0;
Blender* Blender::blenderInstance = nullptr;


Blender::Blender() {
    ctr++;
    std::cout << "New Blender object created. Total number of objects : " << ctr << '\n';
}

Blender::Blender(const Blender& obj) {

}

Blender Blender::operator=(const Blender &obj) {
   return obj;
}

Mat Blender::input(const char* str) {
    Mat image = imread(str);

    if(image.empty()) {
        std::cout << "\n Error loading the images \n";
        exit(1);
    }

    return image;  
}

void Blender::display(const char* str, Mat image) {
    namedWindow(str, WINDOW_NORMAL);
    // Set the window size (width, height) in pixels
    resizeWindow(str, 400, 300);
    // moveWindow(str, 800, 300); 
    imshow(str, image);
    waitKey(0); // waits until a key is pressed
}

Mat Blender::alpha_blender(Mat image1, Mat image2, double alpha, const char* str) {
    // Resize images to the same dimensions (optional)
            resize(image1, image1, image2.size());
            // Define alpha value (transparency)
            //double alpha = 0.7;
            // Perform alpha blending
            Mat blendedImage;
            // addWeighted(image1, alpha, image2, 1.0 - alpha, 0.0, blendedImage);
            addWeighted(image1, alpha, image2, 1.0 - alpha, -20, blendedImage);
            imwrite(str, blendedImage);

            return blendedImage;
}

Blender* Blender::getBlenderInstance() {
     if(blenderInstance == nullptr)
                    blenderInstance = new Blender();
               
            return blenderInstance;
}