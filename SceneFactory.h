/* 
 * File:   SceneFactory.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:49 AM
 */

#ifndef SCENEFACTORY_H
#define	SCENEFACTORY_H

#include "Core.h"
#include "Scene.h"

class SceneFactory {
public:
    static TriangleStoragePtr createStorage();
    static ShapePtr createSphere(const Point& center, float r);
    static ShapePtr createCylinder(const Point& a, const Point& b, float r);
    static ScenePtr createScene(std::string filename);
};

#endif	/* SCENEFACTORY_H */

