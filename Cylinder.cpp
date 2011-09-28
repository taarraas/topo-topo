/* 
 * File:   Cylinder.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 10:43 AM
 */

#include "Cylinder.h"
#include "Geometry.h"

void Cylinder::getTriangles(std::vector<Triangle>& dst) {
    dst.insert(dst.end(), triangles_.begin(), triangles_.end());
}

Cylinder::Cylinder(Point a, Point b, float r, int dCount, int lCount) {
    init(a, b, r, dCount, lCount);   
}

void Cylinder::init(Point a, Point b, float r, int dCount, int lCount) {
    Point u = (b - a).norm();
    Point v, w;
    Geometry::findOrthonormal(u, v, w);
    for (int stripe = 0; stripe < dCount; ++stripe) {
        float beginAngle = 2 * Geometry::PI * stripe / dCount;
        float endAngle = 2 * Geometry::PI * (stripe + 1) / dCount;
        
        Point l1 = a + v * (r * cos(beginAngle)) + w * (r * sin(beginAngle));
        Point l2 = a + v * (r * cos(endAngle)) + w * (r * sin(endAngle));

        Point r1 = b + v * (r * cos(beginAngle)) + w * (r * sin(beginAngle));
        Point r2 = b + v * (r * cos(endAngle)) + w * (r * sin(endAngle));
        
        triangles_.push_back(Triangle(l1, l2, r1));
        triangles_.push_back(Triangle(l1, l2, r2));
    }
}