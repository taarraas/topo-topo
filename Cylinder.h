/* 
 * File:   Cylinder.h
 * Author: taras
 *
 * Created on September 27, 2011, 10:43 AM
 */

#ifndef CYLINDER_H
#define	CYLINDER_H
#include "Core.h"

class Cylinder : public Shape {
    Point begin_;
    Point end_;
    float radius_;
public:
    Cylinder(TriangleStoragePtr storage, Point a, Point b, float r, int dCount, int lCount);
    bool contain(const Point& point) const;
    bool onBound(const Point& point) const;
    Point getIntersection(Point a, Point b);
private:
    void init(Point a, Point b, float r, int dCount, int lCount);
};

#endif	/* CYLINDER_H */

