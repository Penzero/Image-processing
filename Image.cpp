#include "Image.h"

Image::Image() : m_data(nullptr), m_width(0), m_height(0) {}

Image::Image(unsigned int w, unsigned int h): m_width(w), m_height(h){
    m_data = new unsigned char*[m_height];
    for(unsigned int i = 0; i < m_height; i++){
        m_data[i] = new unsigned char[m_width];
        for(unsigned int j = 0; j < m_width; j++){
            m_data[i][j] = 0;
        }
    }
}

Image::Image(const Image &other) : m_width(other.m_width), m_height(other.m_height){
    m_data = new unsigned char*[m_height];
    for(unsigned int i = 0; i < m_height; i++){
        m_data[i] = new unsigned char[m_width];
        for(unsigned int j = 0; j < m_width; j++){
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Image::~Image(){
    release();
}

void Image::release(){
    if(m_data != nullptr){
        for(unsigned int i = 0; i < m_height; i++){
            delete[] m_data[i];
        }
        delete[] m_data;
        m_data = nullptr;
    }
}

Image& Image::operator=(const Image &other){
    if(this != &other){
        release();
        m_width = other.m_width;
        m_height = other.m_height;
        m_data = new unsigned char*[m_height];
        for(unsigned int i = 0; i < m_height; i++){
            m_data[i] = new unsigned char[m_width];
            for(unsigned int j = 0; j < m_width; j++){
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }
    return *this;
}

unsigned char& Image::at(unsigned int x, unsigned int y) {
    if (x >= m_width || y >= m_height) {
        throw std::out_of_range("Pixel coordinates are out of the image bounds.");
    }
    return m_data[y][x];
}

unsigned char& Image::at(Point pt) {
    return at(pt.getX(), pt.getY());
}

unsigned int Image::width() const{
    return m_width;
}

unsigned int Image::height() const{
    return m_height;
}

Size Image::size() const{
    return Size(m_width, m_height);
}

bool Image::isEmpty() const{
    return m_data == nullptr && m_width == 0 && m_height == 0;
}


