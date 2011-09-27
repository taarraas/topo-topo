/* 
 * File:   Scene.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:49 AM
 */

#ifndef SCENE_H
#define	SCENE_H
#include "Core.h"
#include "Shape.h"

class Scene : public Object {
public:
    void getTriangles() { }; //TODO
    Scene();
    void add(ShapePtr shape) { };
private:
    
};

typedef boost::intrusive_ptr<Scene> ScenePtr;

#endif	/* SCENE_H */

