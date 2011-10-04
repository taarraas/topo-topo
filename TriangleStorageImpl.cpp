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
    for(int i = triangles_.size() - 1; i >= 0; i--) {
        Triangle& triangle = triangles_[i];
        bool contain[3];
        int countContain = 0;
        for (int j=0; j < 3; j++) {
            contain[j] = shape->contain(triangle[j]);
            if (contain[j])
                countContain++;            
        }
        
        if (countContain == 0)
            continue;
        
        triangles_.erase(triangles_.begin() + i);
    }
}

void SimpleTriangleStorage::add(const Triangle& tr) {
    triangles_.push_back(tr);
}