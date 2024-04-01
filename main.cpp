#include "Image-processing-class/ImageProcessing.h"
#include "Image-processing-class/ImageConvolution.h"
#include "Image-class/Image.h"
#include "Drawing/Drawing.h"
#include <iostream>

void verification(bool savedSuccessfully) {
    if (!savedSuccessfully) {
        std::cerr << "Failed to save the processed image." << std::endl;
        exit(-1);
    }
}

int main() {
    Image originalImage;

    bool loadedSuccessfully = originalImage.load("Images/barbara.ascii.pgm");

    if (!loadedSuccessfully) {
        std::cerr << "Failed to load the image." << std::endl;
        return -1;
    }

    bool savedSuccessfully;

    Image processedImage;
    GammaCorrection gammaCorrector(0.9);
    gammaCorrector.process(originalImage, processedImage);
    savedSuccessfully = processedImage.save("Images/barbara_gammacorrected.ascii.pgm");
    verification(savedSuccessfully);


    std::vector<std::vector<int>> simpleScaleKernel = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    ImageConvolution convolution(simpleScaleKernel, simpleScale);
    convolution.process(processedImage, processedImage);

    savedSuccessfully = processedImage.save("Images/barbara_imageconvolution.ascii.pgm");
    verification(savedSuccessfully);

    std::cout << "Image processing completed and saved successfully." << std::endl;

    Image image = originalImage;

    Drawing drawing;
    drawing.drawCircle(originalImage, Point(200, 200), 50, 0);
    originalImage.save("Images/barbara_circle.ascii.pgm");
    
    originalImage = image;

    drawing.drawLine(originalImage, Point(100, 100), Point(200, 200), 0);
    originalImage.save("Images/barbara_line.ascii.pgm");

    originalImage = image;

    drawing.drawRectangle(originalImage, Rectangle(Point(100, 100), Size(100, 100)), 0);
    originalImage.save("Images/barbara_rectangle_1.ascii.pgm");

    originalImage = image;

    drawing.drawRectangle(originalImage, Point(100, 100), Point(200, 200), 0);
    originalImage.save("Images/barbara_rectangle_2.ascii.pgm");

    originalImage = image;

    std::cout << "Drawing completed and saved successfully." << std::endl;

    return 0;
}
