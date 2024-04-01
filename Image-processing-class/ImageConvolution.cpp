#include "ImageConvolution.h"

int simpleScale(int value){
    return std::min(std::max(value, 0), 255);
}

void ImageConvolution::process(const Image& src, Image& dst){
    if(kernel.size() % 2 == 0 || kernel[0].size() % 2 == 0){
        std::cerr << "Kernel dimensions must be odd." << std::endl;
        return;
    }

    dst = src;

    int kernelSum = 0;
    for (auto& row : kernel) {
        for (auto& value : row) {
            kernelSum += value;
        }
    }
    if (kernelSum == 0) kernelSum = 1; // Prevent division by zero

    int halfKernelHeight = kernel.size() / 2;
    int halfKernelWidth = kernel[0].size() / 2;

    for(unsigned int y = halfKernelHeight; y < src.height() - halfKernelHeight; y++){
        for(unsigned int x = halfKernelWidth; x < src.width() - halfKernelWidth; x++){
            int newValue = 0;
            for(int ky = -halfKernelHeight; ky <= halfKernelHeight; ky++){
                for(int kx = -halfKernelWidth; kx <= halfKernelWidth; kx++){
                    if ((x + kx) < src.width() && (y + ky) < src.height()) {
                        int pixel = src.at(x + kx, y + ky);
                        int kernelValue = kernel[ky + halfKernelHeight][kx + halfKernelWidth];
                        newValue += pixel * kernelValue;
                    }
                }
            }
            dst.at(x, y) = scaleFunction(newValue / kernelSum);
        }
    }
}