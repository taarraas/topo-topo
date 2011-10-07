#include "Geometry.h"
#include <cmath>

const float Geometry::PI;
const float Geometry::EPS;

bool Geometry::eq(float a, float b) {
    return abs(a - b) < EPS;
}

int Geometry::cmp(float a, float b) {
    return a < b - EPS ? -1 : a > b + EPS ? 1 : 0;
}

float Geometry::det(float a, float b, float c, float d) {
    return a * d - b * c;
}

float Geometry::det(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
    return a * det(e, f, h, i) - b * det(d, f, g, i) + c * det(d, e, g, h);
}

float Geometry::dist(const Point& q, const Point& w) {
    return sqrt((q.x-w.x)*(q.x-w.x) + (q.y-w.y)*(q.y-w.y) + (q.z-w.z)*(q.z-w.z));
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

float Geometry::radian(float x) {
    return x / 180.0 * PI;
}

Point Geometry::orthonormal(const Point & a, const Point & b, const Point & c) {
    return cross(b-a, c-a).norm();
}

void Geometry::makeOrthonormal(const Point & a, Point & b, Point & c) {
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

Triangle Geometry::dir_triangle(const Point & a, const Point & b, const Point & c, const Point & d, int sign) {    
    float f = a.x * det(b.y, b.z, 1, c.y, c.z, 1, d.y, d.z, 1) -
              a.y * det(b.x, b.z, 1, c.x, c.z, 1, d.x, d.z, 1) +
              a.z * det(b.x, b.y, 1, c.x, c.y, 1, d.x, d.y, 1) -
                1 * det(b.x, b.y, b.z, c.x, c.y, c.z, d.x, d.y, d.z);
    if (f * sign > 0)
        return Triangle(a, b, c, orthonormal(a, b, c));
    return Triangle(a, c, b, orthonormal(a, c, b));    
}

Triangle Geometry::ccw_triangle(const Point & a, const Point & b, const Point & c, const Point & d) {    
    return dir_triangle(a, b, c, d, 1);
}

Triangle Geometry::cw_triangle(const Point & a, const Point & b, const Point & c, const Point & d) {    
    return dir_triangle(a, b, c, d, -1);
}

float Geometry::area(float a, float b, float c) {
    float p = (a+b+c)/2;
    return Sqrt(p * (p-a) * (p-b) * (p-c));
}

float Geometry::height(float a, float b, float c) {    
    return 2 * area(a, b, c) / a;
}

#include "Core.h"
float Geometry::height(const Point& a, const Point& b, const Point& c) {
    float A = dist(b, c);
    float B = dist(a, c);
    float C = dist(a, b);
    return height(A, B, C);
}

bool Geometry::isObtuse(float a, float b, float c) {
    return cmp(a * a, b * b + c * c) > 0;
}

std::vector<float> Geometry::quadraticEquation(float a, float b, float c) {
    std::vector<float> sol;
    float d = b*b - 4*a*c;
    if (cmp(d, 0) < 0) return sol;
    d = Sqrt(d);
    sol.push_back((-b - d) / (2 * a));
    if (cmp(d, 0) > 0)
	sol.push_back((-b + d) / (2 * a));
    return sol;
}

float Geometry::Sqrt(float x) {
    //    if (x < -EPS) throw Exception("Geometry::Sqrt : x < -EPS");
    if (x < 0) x = 0;
    return sqrt(x);
}

Geometry::Geometry() {
}

Geometry::~Geometry() {
}

