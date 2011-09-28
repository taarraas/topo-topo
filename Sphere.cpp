/* 
 * File:   Sphere.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 9:45 AM
 */

#include "Sphere.h"

Sphere::Sphere(Point center, float r) {
    init(center, r);
}

void Sphere::getTriangles(std::vector<Triangle>& dst) {
    dst.insert(dst.end(), triangles_.begin(), triangles_.end());
}

void Sphere::init(Point center, float r) {
    //TODO Vlad implement it, please
}

