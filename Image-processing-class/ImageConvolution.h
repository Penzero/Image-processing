#pragma once


#include "ImageProcessing.h"
#include <vector>

typedef int(*ScalingFunction)(int);

int simpleScale(int value);

class ImageConvolution : public ImageProcessing {
    private:
        std::vector<std::vector<int>> kernel;
        ScalingFunction scaleFunction;
    public:
        ImageConvolution(const std::vector<std::vector<int>>& kernel, ScalingFunction scaleFunction): kernel(kernel), scaleFunction(scaleFunction) {}
        virtual void process(const Image& src, Image& dst) override;
};