/* 
 * File:   main.cpp
 * Author: taras
 *
 * Created on September 27, 2011, 9:41 AM
 */

#include <cstdlib>
#include <cstdio>
#include <fstream>
#include "Core.h"
#include "Scene.h"
#include "SceneFactory.h"
#include "OpenGlRenderer.h"
#include "TopoView.h"
#include "TriangleStorageImpl.h"
#include "Renderer.h"
#include "Geometry.h"

/*
 * 
 */

void generateGrid(std::string fileName, int size) {
    std::ofstream genTest (fileName.c_str());
    for (int i = 0; i < size; ++i) {
	for (int j = 0; j < size; ++j) {
	    for (int k = 0; k < size; ++k) {
		for (int vi = i; vi < i+2; ++vi) {
		    for (int vj = j; vj < j+2; ++vj) {
			for (int vk = k; vk < k+2; ++vk) if (vi+vj+vk-i-j-k == 1) {			    
			    genTest << "A " << i << ' ' << j << ' ' << k << " " << vi << ' ' << vj << ' ' << vk << std::endl;
			}
		    }
		}
	    }
	}	
    }
    genTest.close();
}

void run(std::string mapFileName) {
    try {
        ScenePtr scene = SceneFactory::createScene(mapFileName);
        std::vector<Triangle> triangles;
        scene->getTriangles(triangles);
        
        ViewPtr view = new TopoView(triangles);

        RendererPtr renderer = new OpenGlRenderer();
        renderer->run(view);
    } catch (Exception e) {
        LOG_INFO << e.message;
	std::exit(-1);
    }
}

int main(int argc, char** argv) {
    //    generateGrid("gen.map", 2);
    //    run("gen.map");    
    run("sample.map");
    return 0;
}

