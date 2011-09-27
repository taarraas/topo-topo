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
public:
    Sphere();
    void getTriangles(std::vector<Triangle>& dst) { }; //TODO
private:

};

#endif	/* SPHERE_H */

