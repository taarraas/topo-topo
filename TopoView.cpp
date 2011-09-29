#include "TopoView.h"
#include "ViewState.h"
#include "CameraState.h"
#include <GL/glut.h>
#include <cstdio>

void TopoView::init()
{
    fprintf(stderr, "GL_RENDERER   = %s\n", (char *) glGetString(GL_RENDERER));
    fprintf(stderr, "GL_VERSION    = %s\n", (char *) glGetString(GL_VERSION));
    fprintf(stderr, "GL_VENDOR     = %s\n", (char *) glGetString(GL_VENDOR));
    fflush(stderr);
}

void TopoView::reshape(int width, int height)
{    
    std::cout << "reshape" << std::endl;
    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void TopoView::key(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
	exit(0);
    case 'w':
        cameraState.goForward(0.1);
        break;
    case 's':
        cameraState.goBackward(0.1);
        break;
    case 'a':
        cameraState.goLeft(0.1);
        break;
    case 'd':
        cameraState.goRight(0.1);
        break;            
    case 'm':        
        if (params.modelType == ViewParams::SOLID)
            params.modelType = ViewParams::WIRE;
        else
            params.modelType = ViewParams::SOLID;
        
        setModelType(params.modelType);    
        break;
    case 'c':
        params.faceCulling = !params.faceCulling;
        setFaceCulling(params.faceCulling);
        break;      
    default:
	break;
    }

    glutPostRedisplay();
}

void TopoView::draw()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity();     
    glRotatef(cameraState.xrot, 1, 0, 0);
    glRotatef(cameraState.yrot, 0, 1, 0);
    glTranslatef(-cameraState.pos.x, -cameraState.pos.y, -cameraState.pos.z);        

    glColor3f(1.0f,0.0f,0.0f);         
    glBegin(GL_TRIANGLES);                          
    BOOST_FOREACH (Triangle t, triangles_) {        
        for (int v = 0; v < 3; ++v) {
            glVertex3f(t[v].x, t[v].y, t[v].z);
        }
    }
    glEnd(); 
    glFlush();    
    glutSwapBuffers();
}

void TopoView::idle()
{
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.;
    static double t0 = -1.0;
    if (t0 < 0.)
	t0 = t;
    double dt = t - t0;
    t0 = t;
    glutPostRedisplay();
}

void TopoView::mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        viewState.mouseDown = (state == GLUT_DOWN);
        viewState.lastMouseX = x;
        viewState.lastMouseY = y;
    }
}

void TopoView::motion(int x, int y) {    
    if (viewState.mouseDown) {
        cameraState.mouseMovement(x - viewState.lastMouseX, y - viewState.lastMouseY);
        viewState.lastMouseX = x;
        viewState.lastMouseY = y;
    }
}

void TopoView::setModelType(ViewParams::ModelType modelType) {
    switch (modelType) {
        case ViewParams::WIRE:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case ViewParams::SOLID:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        default:            
            break;                    
    }           
}

void TopoView::setFaceCulling(bool faceCulling) {
    if (faceCulling)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}

TopoView::TopoView(const std::vector<Triangle>& triangles) : triangles_(triangles) {    
}
