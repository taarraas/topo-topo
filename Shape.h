/* 
 * File:   Shape.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:42 AM
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include "Core.h"
class Shape : public Object{    
public:
    virtual void getTriangles(std::vector<Triangle>& dst) = 0;
private:

};

typedef boost::intrusive_ptr<Shape> ShapePtr;

#endif	/* SHAPE_H */

