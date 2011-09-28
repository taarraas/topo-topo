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
    default:
	break;
    }

    glutPostRedisplay();
}

void TopoView::draw()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glLoadIdentity(); 
    //glTranslatef(-1.5f,0.0f,-10.0f);

    glColor3f(1.0f,0.0f,0.0f);         
    glBegin(GL_TRIANGLES);                          
    BOOST_FOREACH (Triangle t, triangles_) {        
        for (int v = 0; v < 3; ++v) {
            glVertex3f(t.p[v].x, t.p[v].y, t.p[v].z);
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

TopoView::TopoView(const std::vector<Triangle>& triangles) : triangles_(triangles) {
    
}
