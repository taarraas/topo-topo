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

float Geometry::det(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
    return a * det(e, f, h, i) - b * det(d, f, g, i) + c * det(d, e, g, h);
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
        u = cross(a, p[i]);
        ++i;
    } while (eq(u.abs(), 0));      
    b = cross(u, a).norm();
    c = cross(a, b).norm();    
}

Triangle Geometry::ccw_triangle(const Point & a, const Point & b, const Point & c, const Point & d) {    
    float f = a.x * det(b.y, b.z, 1, c.y, c.z, 1, d.y, d.z, 1) -
              a.y * det(b.x, b.z, 1, c.x, c.z, 1, d.x, d.z, 1) +
              a.z * det(b.x, b.y, 1, c.x, c.y, 1, d.x, d.y, 1) -
                1 * det(b.x, b.y, b.z, c.x, c.y, c.z, d.x, d.y, d.z);
    if (f > 0)
        return Triangle(a, b, c);
    return Triangle(a, c, b);
}

Triangle Geometry::cw_triangle(const Point & a, const Point & b, const Point & c, const Point & d) {    
    float f = a.x * det(b.y, b.z, 1, c.y, c.z, 1, d.y, d.z, 1) -
              a.y * det(b.x, b.z, 1, c.x, c.z, 1, d.x, d.z, 1) +
              a.z * det(b.x, b.y, 1, c.x, c.y, 1, d.x, d.y, 1) -
                1 * det(b.x, b.y, b.z, c.x, c.y, c.z, d.x, d.y, d.z);
    if (f < 0)
        return Triangle(a, b, c);
    return Triangle(a, c, b);
}

Geometry::Geometry() {
}

Geometry::~Geometry() {
}

