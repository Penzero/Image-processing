#include "ImageProcessing.h"

void Brightness::process(const Image& src, Image& dst) {
    std::cout << "Processing image with gain: " << gain << ", bias: " << bias << std::endl;

    // Copy src to dst to ensure dimensions match and dst is initialized
    dst = src;

    for (unsigned int y = 0; y < src.height(); ++y) {
        for (unsigned int x = 0; x < src.width(); ++x) {
            unsigned char pixel = src.at(x, y);
            int newValue = static_cast<int>(pixel) * gain + bias;
            newValue = std::min(std::max(newValue, 0), 255);
            dst.at(x, y) = static_cast<unsigned char>(newValue);
        }
    }

    std::cout << "Image processing completed." << std::endl;
}

void GammaCorrection::process(const Image&src, Image& dst){
    dst = src;
    for(unsigned int y = 0; y < src.height(); ++y){
        for(unsigned int x = 0; x < src.width(); ++x){
            unsigned char pixel = src.at(x, y);
            int newValue = static_cast<int>(pow(pixel, gamma));
            newValue = std::min(std::max(newValue, 0), 255);
            dst.at(x, y) = static_cast<unsigned char>(newValue);
        }
    }
}