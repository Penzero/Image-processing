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

std::ostream& operator<<(std::ostream& os, const Image& img) {
    // PGM Header for P2 format
    os << "P2\n" << img.width() << " " << img.height() << "\n255\n";

    // Writing pixel data as ASCII
    for (unsigned int y = 0; y < img.height(); ++y) {
        for (unsigned int x = 0; x < img.width(); ++x) {
            os << static_cast<int>(img.m_data[y][x]) << " ";
        }
        os << "\n";
    }
    return os;
}

// Stream Extraction Operator (Read Image from Stream in P2 PGM Format)
std::istream& operator>>(std::istream& is, Image& img) {
    std::string line;
    std::getline(is, line); // Read the magic number line
    if (line != "P2") throw std::runtime_error("Unsupported file format or not a P2 PGM file.");

    // Skip comments
    while (is.peek() == '#') {
        std::getline(is, line);
    }

    unsigned int width, height, maxVal;
    is >> width >> height >> maxVal;
    if (maxVal > 255) throw std::runtime_error("Unsupported color depth.");

    // Initialize Image object
    img.release(); // Release any existing data
    img.m_width = width;
    img.m_height = height;
    img.m_data = new unsigned char*[height];
    for (unsigned int i = 0; i < height; ++i) {
        img.m_data[i] = new unsigned char[width];
        for (unsigned int j = 0; j < width; ++j) {
            unsigned int pixelValue;
            is >> pixelValue; // Read each pixel value as an integer
            img.m_data[i][j] = static_cast<unsigned char>(pixelValue);
        }
    }
    return is;
}

bool Image::load(std::string imagePath){
    std::ifstream file(imagePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << imagePath << std::endl;
        return false;
    }
    try {
        file >> *this;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    file.close();
    return true;
}

bool Image::save(std::string imagePath) const{
    std::ofstream file(imagePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << imagePath << std::endl;
        return false;
    }
    file << *this;
    file.close();
    return true;
}

Image Image::zeros(unsigned int width, unsigned int height){
    return Image(width, height);
}

Image Image::ones(unsigned int width, unsigned int height){
    Image img(width, height);
    for(unsigned int y = 0; y < height; y++){
        for(unsigned int x = 0; x < width; x++){
            img.at(x, y) = 1;
        }
    }
    return img;
}

unsigned char* Image::row(int y){
    if(y >= m_height){
        throw std::out_of_range("Row index is out of the image bounds.");
    }
    return m_data[y];
}

Image Image::operator+(const Image &i){
    if(m_width != i.m_width || m_height != i.m_height){
        throw std::invalid_argument("Image dimensions do not match.");
    }
    Image result(m_width, m_height);
    for(unsigned int k = 0; k < m_height; k++){
        for(unsigned int l = 0; l < m_width; l++){
            result.m_data[k][l] = m_data[k][l] + i.m_data[k][l];
        }
    }
    return result;
}

Image Image::operator-(const Image &i){
    if(m_width != i.m_width || m_height != i.m_height){
        throw std::invalid_argument("Image dimensions do not match.");
    }
    Image result(m_width, m_height);
    for(unsigned int k = 0; k < m_height; k++){
        for(unsigned int l = 0; l < m_width; l++){
            result.m_data[k][l] = m_data[k][l] - i.m_data[k][l];
        }
    }
    return result;
}

Image Image::operator*(double s){
    Image result(m_width, m_height);
    for(unsigned int k = 0; k < m_height; k++){
        for(unsigned int l = 0; l < m_width; l++){
            result.m_data[k][l] = static_cast<unsigned char>(m_data[k][l] * s);
        }
    }
    return result;
}

bool Image::getROI(Image &roiImg, Rectangle roiRect){
    return getROI(roiImg, roiRect.getTopLeft().getX(), roiRect.getTopLeft().getY(), roiRect.getSize().getWidth(), roiRect.getSize().getHeight());
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height){
    if(x + width > m_width || y + height > m_height){
        return false;
    }
    roiImg.release();
    roiImg.m_width = width;
    roiImg.m_height = height;
    roiImg.m_data = new unsigned char*[height];
    for(unsigned int i = 0; i < height; i++){
        roiImg.m_data[i] = new unsigned char[width];
        for(unsigned int j = 0; j < width; j++){
            roiImg.m_data[i][j] = m_data[y + i][x + j];
        }
    }
    return true;
}
