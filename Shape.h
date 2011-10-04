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

class TriangleStorage : public Object {
    
public:
    virtual void add(const Triangle& tr) = 0;
    virtual void remove(ShapePtr shape) = 0;
    virtual void getTriangles(std::vector<Triangle>& dst) = 0;       
};

typedef boost::intrusive_ptr<TriangleStorage> TriangleStoragePtr;

class Shape : public Object {
protected:
    TriangleStoragePtr storage_;
    Shape(TriangleStoragePtr storage) : storage_(storage) { } ;
public:
    void getTriangles(std::vector<Triangle>& dst) { storage_->getTriangles(dst); };
    void remove(ShapePtr shape) { storage_->remove(shape); };
    /**
     * Returns point of intersection segment [a, b] to shape
     */
    virtual Point getIntersection(Point a, Point b) = 0;
    virtual bool contain(const Point& point) const = 0;    
private:

};


#endif	/* SHAPE_H */

