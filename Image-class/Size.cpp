#include "Size.h"

bool operator==(const Size& s1, const Size& s2){
    unsigned int area1 = s1.width * s1.height;
    unsigned int area2 = s2.width * s2.height;
    return area1 == area2;
}

bool operator<(const Size& s1, const Size& s2){
    unsigned int area1 = s1.width * s1.height;
    unsigned int area2 = s2.width * s2.height;
    return area1 < area2;
}

bool operator>(const Size& s1, const Size& s2){
    unsigned int area1 = s1.width * s1.height;
    unsigned int area2 = s2.width * s2.height;
    return area1 > area2;
}

bool operator<=(const Size& s1, const Size& s2){
    unsigned int area1 = s1.width * s1.height;
    unsigned int area2 = s2.width * s2.height;
    return area1 <= area2;
}

bool operator>=(const Size& s1, const Size& s2){
    unsigned int area1 = s1.width * s1.height;
    unsigned int area2 = s2.width * s2.height;
    return area1 >= area2;
}
