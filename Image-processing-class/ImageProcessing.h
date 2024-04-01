#pragma once


#include "../Image-class/Image.h"

class ImageProcessing{
    public:
        virtual void process(const Image&src, Image&dst) = 0;

};

class Brightness: public ImageProcessing{
    private:
        double gain;
        int bias;
    public:
        Brightness(double gain = 1.0, int bias = 0): gain(gain), bias(bias) {}
        virtual void process(const Image&src, Image&dst) override;
};

class GammaCorrection: public ImageProcessing{
    private:
        double gamma;
    public:
        GammaCorrection(double gamma = 1.0): gamma(gamma) {}
        virtual void process(const Image&src, Image&dst) override;
};