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

ShapePtr SceneFactory::createSphere(const Point& center, float r) {
    ShapePtr shape = new Sphere();
    return shape;
}

ShapePtr SceneFactory::createCylinder(const Point& a, const Point& b, float r) {
    ShapePtr shape = new Cylinder(a, b, r, 10, 10);
    return shape;
}

ScenePtr SceneFactory::createScene(std::string filename) {
    ScenePtr scene = new Scene();
    scene->add(createCylinder(Point(0, 0, 0), Point(0, 0, 1), 0.5));
    return scene;    
}

