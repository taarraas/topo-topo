#include "TopoView.h"
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
        wire_ = !wire_;
        if (wire_)
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        break;
    case 'c':
        faceCulling_ = !faceCulling_;
        if (faceCulling_)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);
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
    glTranslatef(-1.5f,0.0f,-10.0f);
    glRotatef(rot, 1, 1, 0);

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
    rot += dt * 45;
    glutPostRedisplay();
}

void TopoView::mouse(int button, int state, int x, int y) {
    mouseGrabbed_ = (state == GLUT_DOWN);
}

void TopoView::motion(int x, int y) {
}

TopoView::TopoView(const std::vector<Triangle>& triangles) : triangles_(triangles) {    
    rot = 0;
    wire_ = false;
    faceCulling_ = false;
    mouseGrabbed_ = false;
}
