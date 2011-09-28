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

/*
 * 
 */
int main(int argc, char** argv) {
    ScenePtr scene = SceneFactory::createScene("file.dat");
    RendererPtr renderer = new OpenGlRenderer();
    std::vector<Triangle> triangles;
    scene->getTriangles(triangles);
    ViewPtr view = new TopoView(triangles);
    renderer->run(view);
    return 0;
}

