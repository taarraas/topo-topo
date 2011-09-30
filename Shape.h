/* 
 * File:   Shape.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:42 AM
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include "Core.h"

class Shape;
typedef boost::intrusive_ptr<Shape> ShapePtr;

class Shape : public Object{    
public:
    virtual void getTriangles(std::vector<Triangle>& dst) = 0;
    virtual void remove(ShapePtr shape) = 0;
    virtual bool contain(const Point& point) const = 0;    
private:

};


#endif	/* SHAPE_H */

