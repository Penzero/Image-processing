#include "../Image-class/Image.h"
#include "../Image-class/Point.h"
#include "../Image-class/Rectangle.h"

class Drawing{
    public:
        void drawCircle(Image& image, Point center, int radius, unsigned char color);
        void drawLine(Image& image, Point start, Point end, unsigned char color);
        void drawRectangle(Image& image, Rectangle r, unsigned char color);
        void drawRectangle(Image& image, Point topLeft, Point bottomRight, unsigned char color);
}; 