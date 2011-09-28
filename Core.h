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
#include <set>
#include <boost/intrusive_ptr.hpp>
#include <boost/foreach.hpp>
#include "Object.h"
#include <iostream>

#define LOG_INFO (std::cout << std::endl)

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
    
    friend std::ostream &operator<<(std::ostream &stream, Point p) {
        stream << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    }
    
    bool operator<(const Point& p) const {
        if (x != p.x)
            return x < p.x;
        if (y != p.y)
            return y < p.y;
        if (z != p.z)
            return z < p.z;
        return false;
    }
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

struct Exception {
    std::string message;
    Exception(std::string msg) : message(msg) { };
};

#endif	/* CORE_H */

