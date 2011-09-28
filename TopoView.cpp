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
    glTranslatef(-1.5f,0.0f,-10.0f);
    glRotatef(rtri,0.0f,1.0f,0.0f);

    glBegin(GL_TRIANGLES);                      
    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Front)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);          // Left Of Triangle (Front)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f( 1.0f,-1.0f, 1.0f); 

    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f( 1.0f,-1.0f, -1.0f);  

    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f(-1.0f,-1.0f, -1.0f);  

    glColor3f(1.0f,0.0f,0.0f);          // Red
    glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
    glColor3f(0.0f,0.0f,1.0f);          // Blue
    glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
    glColor3f(0.0f,1.0f,0.0f);          // Green
    glVertex3f(-1.0f,-1.0f, 1.0f);  

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

    rtri += dt * 360 / 5.0;
    glutPostRedisplay();
}



