/* 
 * File:   Sphere.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 9:45 AM
 */

#include "Sphere.h"
#include "Geometry.h"

Sphere::Sphere(Point center, float r)
    : center_(center)
    , radius_(r) {
    init(center, r);
}

void Sphere::getTriangles(std::vector<Triangle>& dst) {
    dst.insert(dst.end(), triangles_.begin(), triangles_.end());
}

Point Sphere::spherePoint(float a, float b) {
    Point p;    
    p.x = sin((a) / 180 * Geometry::PI) * sin((b) / 180 * Geometry::PI);
    p.y = cos((a) / 180 * Geometry::PI) * sin((b) / 180 * Geometry::PI);
    p.z = cos((b) / 180 * Geometry::PI);
    return p;
}

void Sphere::init(Point center, float r) {
    int space = 10;
    for(double b = 0; b <= 180 - space; b+=space) {
        for(double a = 0; a <= 360 - space; a+=space){
            Triangle add;
            add[0] = center + Sphere::spherePoint(a, b) * r;
            add[1] = center + Sphere::spherePoint(a + space, b) * r;
            add[2] = center + Sphere::spherePoint(a, b + space) * r;            
            triangles_.push_back(Geometry::cw_triangle(add[0], add[1], add[2], center));
            
            add[0] = center + Sphere::spherePoint(a + space, b) * r;
            add[1] = center + Sphere::spherePoint(a, b + space) * r;            
            add[2] = center + Sphere::spherePoint(a + space, b + space) * r;
            triangles_.push_back(Geometry::cw_triangle(add[0], add[1], add[2], center));            
        }
    }
}

void Sphere::remove(ShapePtr shape) {
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

bool Sphere::contain(const Point& point) const {
    return (point-center_).abs() < radius_;
}
