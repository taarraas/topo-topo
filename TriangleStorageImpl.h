/* 
 * File:   TriangleStorage.h
 * Author: taras
 *
 * Created on October 4, 2011, 9:01 AM
 */

#ifndef TRIANGLESTORAGE_H
#define	TRIANGLESTORAGE_H

#include "Core.h"

class SimpleTriangleStorage : public TriangleStorage {
    std::vector<Triangle> triangles_;
    static void addTriangles(ShapePtr shape, const std::vector<Point>& in, const std::vector<Point>& out, std::vector<Triangle>& dst, const Triangle& original);
    static void sortBySameOrder(std::vector<Point>& sorted, const Triangle& order);
public:
    void getTriangles(std::vector<Triangle>& dst);
    void add(const Triangle& tr);
    void remove(ShapePtr shape);    
};

#endif	/* TRIANGLESTORAGE_H */

