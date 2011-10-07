cmake_minimum_required (VERSION 2.6)
project (topo-topo)

#set(CMAKE_MODULE_PATH "cmake/modules/" ${CMAKE_MODULE_PATH})
#set(CMAKE_INSTALL_PREFIX Debug)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "output")
set(CMAKE_INSTALL_PREFIX "bin/")

#configure boost
#set (Boost_USE_STATIC_LIBS off)
#set (Boost_DEBUG on)
#set (Boost_USE_MULTITHREADED on)
#find_package (Boost COMPONENTS system REQUIRED)
#link_directories (${Boost_LIBRARY_DIRS})
#include_directories(${Boost_INCLUDE_DIRS})

set(TOPO_SOURCES
	CameraState.cpp  
	Geometry.cpp  
	MapParser.cpp  
	OpenGlRenderer.cpp  
	Scene.cpp	    
	Sphere.cpp	  
	TriangleStorageImpl.cpp  
	ViewParams.cpp 
	Cylinder.cpp	 
	main.cpp      
	Object.cpp
     	Renderer.cpp	  
	SceneFactory.cpp  
	TopoView.cpp  
	View.cpp		 
	ViewState.cpp)


add_executable(topo-topo ${TOPO_SOURCES})
#target_link_libraries(topo-topo ${Boost_LIBRARIES})
target_link_libraries(topo-topo GL GLU glut boost_system)
install (TARGETS topo-topo DESTINATION .)


source_group("Headers" FILES Sphere.h)
source_group("Sources" FILES Sphere.cpp)

#message(${EXECUTABLE_OUTPUT_PATH})
