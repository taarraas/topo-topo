#include "Geometry.h"
#include <cmath>

const float Geometry::PI;
const float Geometry::EPS;

bool Geometry::eq(float a, float b) {
    return abs(a - b) < EPS;
}

float Geometry::det(float a, float b, float c, float d) {
    return a * d - b * c;
}

float Geometry::dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point Geometry::cross(const Point & a, const Point & b) {
    return Point(
            det(a.y, a.z, b.y, b.z),
            -det(a.x, a.z, b.x, b.z),
            det(a.x, a.y, b.x, b.y)
           );
}

void Geometry::findOrthonormal(const Point & a, Point & b, Point & c) {
    static Point p[4] = 
    { 
       Point(sqrt(2), sqrt(11), sqrt(19)),
       Point(sqrt(3), sqrt(13), sqrt(21)),
       Point(sqrt(5), sqrt(15), sqrt(23)),
       Point(sqrt(7), sqrt(17), sqrt(27))
    };
    Point u;
    int i = 0;
    do {
        u = cross(u, p[i]);
    } while (!eq(u.abs(), 0));
    b = cross(u, a).norm();
    c = cross(a, b).norm();    
}

Geometry::Geometry() {
}

Geometry::~Geometry() {
}

