/* 
 * File:   Cylinder.h
 * Author: taras
 *
 * Created on September 27, 2011, 10:43 AM
 */

#ifndef CYLINDER_H
#define	CYLINDER_H
#include "Core.h"
#include "Shape.h"

class Cylinder : public Shape {
public:
    Cylinder();
    void getTriangles(std::vector<Triangle>& dst) { }; //TODO
private:

};

#endif	/* CYLINDER_H */

