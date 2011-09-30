/* 
 * File:   Geometry.h
 * Author: vlad
 *
 * Created on September 28, 2011, 11:01 AM
 */

#ifndef GEOMETRY_H
#define	GEOMETRY_H

#include "Core.h"

class Geometry {
public:    
    static const float EPS = 1e-9;
    static const float PI = M_PI;
    static Point cross(const Point & a, const Point & b);
    static float det(float a, float b, float c, float d);
    static float det(float a, float b, float c, float d, float e, float f, float g, float h, float i);
    static float dot(const Point & a, const Point & b);
    static bool eq(float a, float b);        
    static int cmp(float a, float b);
    static void findOrthonormal(const Point & a, Point & b, Point & c);    
    static float radian(float x);
    static Triangle ccw_triangle(const Point & a, const Point & b, const Point & c, const Point & d);
    static Triangle cw_triangle(const Point & a, const Point & b, const Point & c, const Point & d);
    static float area(float a, float b, float c);
    static float height(float a, float b, float c);
    static bool isObtuse(float a, float b, float c);    
    virtual ~Geometry();
private:
    Geometry();
};

#endif	/* GEOMETRY_H */

