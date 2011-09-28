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
    try {
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

