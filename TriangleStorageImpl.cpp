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

void SimpleTriangleStorage::remove(ShapePtr shape) {
    std::vector<Triangle> newTriangles;
    for(int i = triangles_.size() - 1; i >= 0; i--) {
        Triangle& triangle = triangles_[i];
        
        std::vector<int> in;
        for (int j = 0; j < 3; j++) {
            if (shape->contain(triangle[j]))
                in.push_back(j);
        }
	triangles_.erase(triangles_.begin() + i);
	if (in.size() == 3) continue;
	if (in.size() == 1) {
	    std::cout << "case1" << std::endl;
	    Point q = shape->getIntersection(triangle[in[0]], triangle[(in[0] + 1) % 3]);
	    Point w = shape->getIntersection(triangle[in[0]], triangle[(in[0] + 2) % 3]);

	    newTriangles.push_back(Triangle(q, 
					    triangle[(in[0] + 1) % 3], 
					    triangle[(in[0] + 2) % 3],
					    triangle.norm));

	    newTriangles.push_back(Triangle(triangle[(in[0] + 2) % 3], 
					    w, 
					    q,
					    triangle.norm));
	} else {
	    std::cout << "case2" << std::endl;
	    if (in[0] == 0 && in[1] == 2) std::swap(in[0], in[1]);
	    int out = (in[1] + 1) % 3;
	    Point q = shape->getIntersection(triangle[out], triangle[in[0]]);
	    Point w = shape->getIntersection(triangle[out], triangle[in[1]]);
	    newTriangles.push_back(Triangle(triangle[out], q, w, triangle.norm));
	    std::cout << "~case2" << std::endl;
	}   
	
    }
    triangles_.insert(triangles_.end(), newTriangles.begin(), newTriangles.end());    
}

void SimpleTriangleStorage::add(const Triangle& tr) {
    triangles_.push_back(tr);
}
