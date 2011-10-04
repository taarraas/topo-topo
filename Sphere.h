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
    Point center_;
    float radius_;
public:
    Sphere(TriangleStoragePtr storage, Point center, float r, int Count);
    bool contain(const Point& point) const;    
private:
    void init(Point center, float r, int Count);    
    static Point spherePoint(float a, float b);
};

#endif	/* SPHERE_H */

