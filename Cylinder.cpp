/* 
 * File:   Cylinder.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 10:43 AM
 */

#include "Cylinder.h"

void Cylinder::getTriangles(std::vector<Triangle>& dst) {
    dst.insert(dst.end(), triangles_.begin(), triangles_.end());
}

Cylinder::Cylinder(Point a, Point b, float r, int dCount, int lCount) {
    init(a, b, r, dCount, lCount);   
}

void Cylinder::init(Point a, Point b, float r, int dCount, int lCount) {
}