/* 
 * File:   Sphere.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:45 AM
 */

#ifndef SPHERE_H
#define	SPHERE_H
#include "Shape.h"

class Sphere : public Shape {
    std::vector<Triangle> triangles_;
    Point center_;
    float radius_;
public:
    Sphere(Point center, float r);
    void getTriangles(std::vector<Triangle>& dst);
    void remove(ShapePtr shape);
    bool contain(const Point& point) const;    
private:
    void init(Point center, float r);
};

#endif	/* SPHERE_H */

