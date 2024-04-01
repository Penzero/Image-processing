#pragma once


class Point{
    private:
        int x;
        int y;
    public:
        Point(int x, int y) : x(x), y(y) {}; //parameterized constructor
        Point(): x(0), y(0) {}; //default constructor

        int getX() const {return x;}
        int getY() const {return y;}

        void setX(int x) {this->x = x;}
        void setY(int y) {this->y = y;}
};