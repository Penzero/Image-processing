#pragma once

class Size{
    private:
        unsigned int width;
        unsigned int height;
    public:
        Size(unsigned int width, unsigned int height) : width(width), height(height) {}; //parameterized constructor
        Size() : width(0), height(0) {}; //default constructor

        unsigned int getWidth() const {return width;};
        unsigned int getHeight() const {return height;}

        void setWidth(unsigned int width) {this->width = width;};
        void setHeight(unsigned int height) {this->height = height;};

        friend bool operator==(const Size& s1, const Size& s2);
        friend bool operator<(const Size& s1, const Size& s2);
        friend bool operator>(const Size& s1, const Size& s2);
        friend bool operator<=(const Size& s1, const Size& s2);
        friend bool operator>=(const Size& s1, const Size& s2);
};