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
#include <boost/intrusive_ptr.hpp>
#include <boost/foreach.hpp>
#include "Object.h"

struct Point {
    float x;
    float y;
    float z;
    Point() : x(0), y(0), z(0) { };
    Point(float cx, float cy, float cz) : x(cx), y(cy), z(cz) { };
};

struct Triangle {
    Point p[3];
    Triangle () { 
        p[0] = Point(); 
        p[1] = Point(); 
        p[2] = Point();
    };
};

#endif	/* CORE_H */

