/* 
 * File:   SceneFactory.cpp
 * Author: taras
 * 
 * Created on September 27, 2011, 9:49 AM
 */

#include "SceneFactory.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Scene.h"

ShapePtr SceneFactory::createSphere(const Point& center) {
    ShapePtr shape = new Sphere();
    return shape;
}

ShapePtr SceneFactory::createCylinder(const Point& a, const Point& b) {
    ShapePtr shape = new Cylinder();
    return shape;
}

ScenePtr SceneFactory::createScene(std::string filename) {
    ScenePtr scene = new Scene();
    return scene;    
}

