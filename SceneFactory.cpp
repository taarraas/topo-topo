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
#include "TriangleStorageImpl.h"

TriangleStoragePtr SceneFactory::createStorage() {
    return new SimpleTriangleStorage();
}

ShapePtr SceneFactory::createSphere(const Point& center, float r) {
    TriangleStoragePtr storage = createStorage();
    ShapePtr shape = new Sphere(storage, center, r, 30);
    LOG_INFO << "Created sphere " << center << ", radius = " << r;
    return shape;
}

ShapePtr SceneFactory::createCylinder(const Point& a, const Point& b, float r) {
    TriangleStoragePtr storage = createStorage();
    ShapePtr shape = new Cylinder(storage, a, b, r, 10, 10);
    LOG_INFO << "Created cylinder " << a << " - " << b << ", radius = " << r;
    return shape;
}

ScenePtr SceneFactory::createScene(std::string filename) {
    const float r = 0.3;
    ScenePtr scene = new Scene();
    MapParser parser(filename);
    MapParser::MapElement el;
    std::set<Point> alreadyAddedPoints;    
    while (parser.next(el)) {
	scene->add(createCylinder(el.from, el.to, r));	
	/*	if (alreadyAddedPoints.find(el.from) != alreadyAddedPoints.end())
            scene->add(createSphere(el.from, r));
        else
            alreadyAddedPoints.insert(el.from);
        
        if (alreadyAddedPoints.find(el.to) != alreadyAddedPoints.end())
            scene->add(createSphere(el.to, r));
        else
	alreadyAddedPoints.insert(el.to);      */
    }
    return scene;    
}

