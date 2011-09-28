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
#include "MapParser.h"

ShapePtr SceneFactory::createSphere(const Point& center, float r) {
    ShapePtr shape = new Sphere();
    return shape;
}

ShapePtr SceneFactory::createCylinder(const Point& a, const Point& b, float r) {
    LOG_INFO << "Created cylinder " << a << " - " << b << ", radius = " << r;
    ShapePtr shape = new Cylinder(a, b, r, 10, 10);
    return shape;
}

ScenePtr SceneFactory::createScene(std::string filename) {
    const float r = 0.3;
    ScenePtr scene = new Scene();
    MapParser parser(filename);
    MapParser::MapElement el;
    while (parser.next(el)) {
        scene->add(createCylinder(el.from, el.to, r));
    }
    return scene;    
}

