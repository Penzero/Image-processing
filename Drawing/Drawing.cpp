#include "Drawing.h"


//Draws a circle with a given center and radius
void Drawing::drawCircle(Image& image, Point center, int radius, unsigned char color) {
    for (int y = center.getY() - radius; y <= center.getY() + radius; y++) {
        for (int x = center.getX() - radius; x <= center.getX() + radius; x++) {
            if (std::sqrt(std::pow(x - center.getX(), 2) + std::pow(y - center.getY(), 2)) <= radius) {
                image.at(x, y) = color;
            }
        }
    }
}

//Draws a line between two points using Bresenham's line algorithm
void Drawing::drawLine(Image& image, Point start, Point end, unsigned char color) {
    int dx = std::abs(end.getX() - start.getX()), sx = start.getX() < end.getX() ? 1 : -1;
    int dy = -std::abs(end.getY() - start.getY()), sy = start.getY() < end.getY() ? 1 : -1;
    int err = dx + dy, e2;

    for (;;) {
        image.at(start.getX(), start.getY()) = color;
        if (start.getX() == end.getX() && start.getY() == end.getY()) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; start.setX(start.getX() + sx); }
        if (e2 <= dx) { err += dx; start.setY(start.getY() + sy); }
    }
}

//Draws a rectangle given a rectangle object
void Drawing::drawRectangle(Image& image, Rectangle r, unsigned char color) {
    Point topLeft = r.getTopLeft();
    Size size = r.getSize();
    drawRectangle(image, topLeft, Point(topLeft.getX() + size.getWidth(), topLeft.getY() + size.getHeight()), color);
}


//Draws a rectangle given two points
void Drawing::drawRectangle(Image& image, Point topLeft, Point bottomRight, unsigned char color) {
    // Draw top and bottom lines
    for (int x = topLeft.getX(); x <= bottomRight.getX(); x++) {
        image.at(x, topLeft.getY()) = color;
        image.at(x, bottomRight.getY()) = color;
    }
    // Draw left and right lines
    for (int y = topLeft.getY(); y <= bottomRight.getY(); y++) {
        image.at(topLeft.getX(), y) = color;
        image.at(bottomRight.getX(), y) = color;
    }
}