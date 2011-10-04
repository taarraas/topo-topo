/* 
 * File:   Scene.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:49 AM
 */

#ifndef SCENE_H
#define	SCENE_H
#include "Core.h"

class Scene : public Object {
public:
    void getTriangles(std::vector<Triangle>& dst);
    Scene();
    void add(ShapePtr shape);
private:
    std::vector<ShapePtr> shapes_;
};

typedef boost::intrusive_ptr<Scene> ScenePtr;

#endif	/* SCENE_H */

