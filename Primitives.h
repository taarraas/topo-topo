/* 
 * File:   Primitives.h
 * Author: taras
 *
 * Created on October 4, 2011, 10:10 AM
 */

#ifndef PRIMITIVES_H
#define	PRIMITIVES_H

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
    Point norm;
    
    Triangle () { 
        p[0] = Point(); 
        p[1] = Point(); 
        p[2] = Point();
        norm = Point(0, 0, 1);
    }
    
    Triangle(const Point & p0, const Point & p1, const Point & p2, const Point & norm) : norm(norm) {
        p[0] = p0;
        p[1] = p1;
        p[2] = p2;        
    }
    Point& operator [] (int index) {
        return p[index];
    }
    
    const Point& operator [] (int index) const {
        return p[index];
    }
};

#endif	/* PRIMITIVES_H */

