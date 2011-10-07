/* 
 * File:   main.cpp
 * Author: taras
 *
 * Created on September 27, 2011, 9:41 AM
 */

#include <cstdlib>
#include "Core.h"
#include "Scene.h"
#include "SceneFactory.h"
#include "OpenGlRenderer.h"
#include "TopoView.h"
#include "Renderer.h"
#include "Geometry.h"

/*
 * 
 */

#include "Cylinder.h"
#include "TriangleStorageImpl.h"
void testCylinder() {
    TriangleStoragePtr storage = new SimpleTriangleStorage();
    Point a = Point(0, 0, 0);	
    Point b = Point(0, 10, 0);	
    float r = 2;
    ShapePtr shape = new Cylinder(storage, a, b, r, 10, 10);
    Point q = Point(2, 2, 2);
    Point w = Point(0, 2, 1);
    LOG_INFO << shape->getIntersection(q, w) << std::endl;
}

int main(int argc, char** argv) {
    try {
		// testCylinder();
		// return 0;
        ScenePtr scene = SceneFactory::createScene("sample.map");
        std::vector<Triangle> triangles;
        scene->getTriangles(triangles);
        
        ViewPtr view = new TopoView(triangles);

        RendererPtr renderer = new OpenGlRenderer();
        renderer->run(view);
    } catch (Exception e) {
        LOG_INFO << e.message;
        return -1;
    }
    return 0;
}

