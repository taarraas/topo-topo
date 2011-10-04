/* 
 * File:   Sphere.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 9:45 AM
 */

#include "Sphere.h"
#include "Geometry.h"

Sphere::Sphere(TriangleStoragePtr storage, Point center, float r, int Count)
    : Shape(storage)
    , radius_(r)
    , center_(center) {
    init(center, r, Count);
}

Point Sphere::getIntersection(Point a, Point b) {
    // TODO implement
    return Point();
}

Point Sphere::spherePoint(float a, float b) {
    return Point(sin(a) * sin(b), cos(a) * sin(b), cos(b));
}

void Sphere::init(Point center, float r, int Count) {
    double b_add = Geometry::PI / Count;
    double a_add = 2 * Geometry::PI / Count;
    for(int b_seg = 0; b_seg < Count; ++b_seg) {
        for(int a_seg = 0; a_seg < Count; ++a_seg){
            double b = b_add * b_seg;
            double a = a_add * a_seg;
            Triangle add;
            add[0] = center + Sphere::spherePoint(a, b) * r;
            add[1] = center + Sphere::spherePoint(a + a_add, b) * r;
            add[2] = center + Sphere::spherePoint(a, b + b_add) * r;            
            storage_->add(Geometry::cw_triangle(add[0], add[1], add[2], center));
            
            add[0] = center + Sphere::spherePoint(a + a_add, b + b_add) * r;
            storage_->add(Geometry::cw_triangle(add[0], add[1], add[2], center));            
        }
    }
}

bool Sphere::contain(const Point& point) const {
    return (point-center_).abs() < radius_;
}
