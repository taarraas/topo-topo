/* 
 * File:   Scene.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 9:49 AM
 */

#include "Scene.h"

Scene::Scene() {
}

void Scene::getTriangles(std::vector<Triangle>& dst) {
    BOOST_FOREACH(ShapePtr shape, shapes_) {
        shape->getTriangles(dst);
    }
}

void Scene::add(ShapePtr shape) { 
    shapes_.push_back(shape); 
}


