/* 
 * File:   Core.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:44 AM
 */

#ifndef CORE_H
#define	CORE_H

#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <boost/intrusive_ptr.hpp>
#include <boost/foreach.hpp>
#include "Object.h"

struct Point {
    float x;
    float y;
    float z;
    Point() : x(0), y(0), z(0) { };
    Point(float cx, float cy, float cz) : x(cx), y(cy), z(cz) { };
    Point operator - (const Point & g) const {
        return Point(x - g.x, y - g.y, z - g.z);
    }
    Point operator + (const Point & g) const {
        return Point(x + g.x, y + g.y, z + g.z);
    }
    Point operator * (float v) const {
        return Point(x * v, y * v, z * v);
    }        
    Point operator / (float v) const {
        return Point(x / v, y / v, z / v);
    }        
    float abs2() const { return x*x + y*y + z*z; }
    float abs() const { return sqrt(abs2()); }
    Point norm() const { return *this / abs(); }
};

struct Triangle {
    Point p[3];
    Triangle () { 
        p[0] = Point(); 
        p[1] = Point(); 
        p[2] = Point();
    }
    Triangle(const Point & p0, const Point & p1, const Point & p2) {
        p[0] = p0;
        p[1] = p1;
        p[2] = p2;
    }
};

#endif	/* CORE_H */

