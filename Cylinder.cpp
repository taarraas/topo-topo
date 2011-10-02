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

Cylinder::Cylinder(Point a, Point b, float r, int dCount, int lCount) 
    : begin_(a)
    , end_(b)
    , radius_(r) {
    init(a, b, r, dCount, lCount);   
}

void Cylinder::remove(ShapePtr shape) {
    for(int i = triangles_.size() - 1; i >= 0; i--) {
        Triangle& triangle = triangles_[i];
        bool contain[3];
        int countContain = 0;
        for (int j=0; j < 3; j++) {
            contain[j] = shape->contain(triangle[j]);
            if (contain[j])
                countContain++;            
        }
        
        if (countContain == 0)
            continue;
        
        triangles_.erase(triangles_.begin() + i);
    }
}

bool Cylinder::contain(const Point& point) const {
    float b = dist(point, begin_);
    float c = dist(point, end_);
    float a = dist(begin_, end_);
    return !Geometry::isObtuse(a, b, c) && Geometry::cmp(Geometry::height(a, b, c), radius_) < 0;
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
        
        Point vup = (r1 - l1) / lCount;
        Point vdown = (r2 - l2) / lCount;
        
        Point rectLU = l1, rectRU = l1 + vup;
        Point rectLD = l2, rectRD = l2 + vdown;
        for (int len = 0; len < lCount; ++len) {
            triangles_.push_back(Geometry::cw_triangle(rectLU, rectRD, rectRU, a));
            triangles_.push_back(Geometry::cw_triangle(rectLU, rectRD, rectLD, a));
            
            rectLU = rectRU;
            rectLD = rectRD;
            rectRU = rectRU + vup;
            rectRD = rectRD + vdown;
        }        
    }
}