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
    };
};

struct Exception {
    std::string message;
    Exception(std::string msg) : message(msg) { };
};

#endif	/* CORE_H */

