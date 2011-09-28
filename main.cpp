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
#include <iostream>

/*
 * 
 */
int main(int argc, char** argv) {
    try {
        ScenePtr scene = SceneFactory::createScene("sample.map");
        RendererPtr renderer = new OpenGlRenderer();
        std::vector<Triangle> triangles;
        scene->getTriangles(triangles);
        ViewPtr view = new TopoView(triangles);
        renderer->run(view);
    } catch (Exception e) {
        std::cout << e.message << std::endl;
        return -1;
    }
    return 0;
}

