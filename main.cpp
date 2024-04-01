#include "Image-processing-class/ImageProcessing.h"
#include "Image-class/Image.h"
#include <iostream>

int main() {
    Image originalImage;

    bool loadedSuccessfully = originalImage.load("Images/barbara.ascii.pgm");

    if (!loadedSuccessfully) {
        std::cerr << "Failed to load the image." << std::endl;
        return -1;
    }

    Image processedImage;
    Brightness brightnessAdjuster(1.6, 10);
    brightnessAdjuster.process(originalImage, processedImage);

    bool savedSuccessfully = processedImage.save("Images/barbara_brightened.ascii.pgm");
    if (!savedSuccessfully) {
        std::cerr << "Failed to save the processed image." << std::endl;
        return -1;
    }

    std::cout << "Image processing completed and saved successfully." << std::endl;

    return 0;
}
