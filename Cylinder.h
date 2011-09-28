/* 
 * File:   Cylinder.h
 * Author: taras
 *
 * Created on September 27, 2011, 10:43 AM
 */

#ifndef CYLINDER_H
#define	CYLINDER_H
#include "Core.h"
#include "Shape.h"

class Cylinder : public Shape {
    std::vector<Triangle> triangles_;
public:
    Cylinder(Point a, Point b, float r, int dCount, int lCount);
    void getTriangles(std::vector<Triangle>& dst);
private:
    void init(Point a, Point b, float r, int dCount, int lCount);
};

#endif	/* CYLINDER_H */

