/* 
 * File:   TriangleStorage.cpp
 * Author: taras
 * 
 * Created on October 4, 2011, 9:01 AM
 */

#include "Core.h"
#include "TriangleStorageImpl.h"

void SimpleTriangleStorage::getTriangles(std::vector<Triangle>& dst) {
    dst.insert(dst.end(), triangles_.begin(), triangles_.end());
}

void SimpleTriangleStorage::sortBySameOrder(std::vector<Point>& sorted, const Triangle& order) {
    //TODO
}

void SimpleTriangleStorage::addTriangles(ShapePtr shape, const std::vector<Point>& in, const std::vector<Point>& out, std::vector<Triangle>& dst, const Triangle& original) {
    std::vector<Point> edge;
    BOOST_FOREACH(const Point& inP, in) {
        BOOST_FOREACH(const Point& outP, out) {
            Point edgePoint = shape->getIntersection(inP, outP);
            edge.push_back(edgePoint);
        }
    }

    std::vector<Point> hull;
    hull.insert(hull.end(), out.begin(), out.end());
    hull.insert(hull.end(), edge.begin(), edge.end());
    
    if (hull.size() < 3)
        throw Exception("SimpleTriangleStorage::addTriangles : Data inconsistency : hull size = " + hull.size());
    
    sortBySameOrder(hull, original);
    for(size_t i = 1; i < hull.size() - 1; i++) {
        Triangle tr(hull[0], hull[i], hull[i + 1], original.norm);
        dst.push_back(tr);
    }
}

void SimpleTriangleStorage::remove(ShapePtr shape) {
    std::vector<Triangle> newTriangles;
    for(int i = triangles_.size() - 1; i >= 0; i--) {
        Triangle& triangle = triangles_[i];
        
        std::vector<Point> in, out;
        for (int j = 0; j < 3; j++) {
            if (shape->contain(triangle[j]))
                in.push_back(triangle[j]);
            else
                out.push_back(triangle[j]);
        }
        
        if (in.size() == 0)
            continue;
        
        Triangle originalTriangle = triangles_[i];
        
        triangles_.erase(triangles_.begin() + i);
        
        if (in.size() == 3)
            continue;
        
        //TODO uncomment after implementation of intersections
        //addTriangles(shape, in, out, newTriangles, originalTriangle);
    }
    triangles_.insert(triangles_.end(), newTriangles.begin(), newTriangles.end());    
}

void SimpleTriangleStorage::add(const Triangle& tr) {
    triangles_.push_back(tr);
}