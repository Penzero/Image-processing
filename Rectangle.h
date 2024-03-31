#include "Point.h"
#include "Size.h"

class Rectangle{
    private:
        Point topLeft;
        Size size;
    public:
        Rectangle(Point topLeft, Size size) : topLeft(topLeft), size(size) {}; //parameterized constructor
        Rectangle() : topLeft(Point()), size(Size()){}; //default constructor

        Point getTopLeft(){return topLeft;};
        Size getSize(){return size;};

        void setTopLeft(Point topLeft){this->topLeft = topLeft;};
        void setSize(Size size){this->size = size;};
        
        friend Rectangle operator+(Rectangle& r1, Point p);
        friend Rectangle operator-(Rectangle& r1, Point p);

        friend Rectangle operator&(Rectangle& r1, Rectangle& r2);
        friend Rectangle operator|(Rectangle& r1, Rectangle& r2);
};