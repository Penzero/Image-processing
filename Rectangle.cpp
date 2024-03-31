#include "Rectangle.h"
#include <algorithm>

Rectangle operator+(Rectangle& r1, Point p){
    Point newTopLeft = Point(r1.topLeft.getX() + p.getX(), r1.topLeft.getY() + p.getY());
    return Rectangle(newTopLeft, r1.size);
}

Rectangle operator-(Rectangle& r1, Point p){
    Point newTopLeft = Point(r1.topLeft.getX() - p.getX(), r1.topLeft.getY() - p.getY());
    return Rectangle(newTopLeft, r1.size);
}

Rectangle operator&(Rectangle& r1, Rectangle& r2){
    int x1 = std::max(r1.topLeft.getX(), r2.topLeft.getX());
    int y1 = std::max(r1.topLeft.getY(), r2.topLeft.getY());
    int x2 = std::min(r1.topLeft.getX() + r1.size.getWidth(), r2.topLeft.getX() + r2.size.getWidth());    
    int y2 = std::min(r1.topLeft.getY() + r1.size.getHeight(), r2.topLeft.getY() + r2.size.getHeight());

    if (x1 < x2 && y1 < y2) {
        Point newTopLeft(x1, y1);
        Size newSize(x2 - x1, y2 - y1);
        return Rectangle(newTopLeft, newSize);
    }
    return Rectangle();  
}

Rectangle operator|(Rectangle& r1, Rectangle& r2){
    int x1 = std::min(r1.topLeft.getX(), r2.topLeft.getX());
    int y1 = std::min(r1.topLeft.getY(), r2.topLeft.getY());
    int x2 = std::max(r1.topLeft.getX() + r1.size.getWidth(), r2.topLeft.getX() + r2.size.getWidth());    
    int y2 = std::max(r1.topLeft.getY() + r1.size.getHeight(), r2.topLeft.getY() + r2.size.getHeight());

    Point newTopLeft(x1, y1);
    Size newSize(x2 - x1, y2 - y1);
    return Rectangle(newTopLeft, newSize);
}