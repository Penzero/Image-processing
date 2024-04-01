#include "Image-processing-class/ImageProcessing.h"
#include "Image-processing-class/ImageConvolution.h"
#include "Image-class/Image.h"
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

    return 0;
}
