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
    if ((contain(a) && contain(b)) || (!contain(a) && !contain(b))) {
        throw Exception("Sphere::getIntersection : External data inconsistency : given segment(!) doesn't intersect sphere");
    }
    Point delta = b-a;
    a = a - center_;
    std::vector<float> t = Geometry::quadraticEquation(
						       delta.x * delta.x + delta.y * delta.y + delta.z * delta.z,
						       2 * (delta.x * a.x + delta.y * a.y + delta.z * a.z),
						       a.x * a.x + a.y * a.y + a.z * a.z - radius_ * radius_);

    BOOST_FOREACH(float x, t) {
	if (Geometry::cmp(x, 0) < 0 || Geometry::cmp(x, 1) > 0) continue;	
	Point tupitupi = b - delta * x;
	std::cout << Geometry::dist(tupitupi, center_) << ' ' << radius_ << std::endl;
    }    
    throw Exception("Sphere::getIntersection : External data inconsistency : given segment(!) doesn't intersect sphere");    
    //return Point();
}

Point Sphere::spherePoint(float a, float b) {
    return Point(sin(a) * sin(b), cos(a) * sin(b), cos(b));
}

void Sphere::init(Point center, float r, int Count) {
    float b_add = Geometry::PI / Count;
    float a_add = 2 * Geometry::PI / Count;
    for(int b_seg = 0; b_seg < Count; ++b_seg) {
        for(int a_seg = 0; a_seg < Count; ++a_seg){
            float b = b_add * b_seg;
            float a = a_add * a_seg;
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
    return Geometry::cmp(Geometry::dist(point, center_), radius_) < 0;
}
