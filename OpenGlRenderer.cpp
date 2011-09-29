#include "OpenGlRenderer.h"
#include "View.h"
#include "TopoView.h"
#include <GL/glut.h>
#include <cstdlib>

ViewPtr OpenGlRenderer::view;

void OpenGlRenderer::reshape(int width, int height) {
    OpenGlRenderer::view->reshape(width, height);
}

void OpenGlRenderer::key(unsigned char key, int x, int y) {
    OpenGlRenderer::view->key(key, x, y);
}

void OpenGlRenderer::draw() {
    OpenGlRenderer::view->draw();
}

void OpenGlRenderer::idle() {
    OpenGlRenderer::view->idle();
}

void OpenGlRenderer::mouse(int button, int state, int x, int y) {
    OpenGlRenderer::view->mouse(button, state, x, y);
}

void OpenGlRenderer::motion(int x, int y) {
    OpenGlRenderer::view->motion(x, y);
}

void OpenGlRenderer::visible(int vis) {
    if (vis == GLUT_VISIBLE)
	glutIdleFunc(OpenGlRenderer::idle);
    else
	glutIdleFunc(NULL);
}

void OpenGlRenderer::run(ViewPtr view) {
    OpenGlRenderer::view = view;
    
    GLenum type;

    int * pargc = new int(0);
    char ** argv = new char*[0];    
    glutInit(pargc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);

    type = GLUT_RGB | GLUT_ALPHA | GLUT_DOUBLE;
    glutInitDisplayMode(type);

    glutCreateWindow("OpenGlRenderer");

    view->init();

    glutMouseFunc(OpenGlRenderer::mouse);
    glutMotionFunc(OpenGlRenderer::motion);
    glutReshapeFunc(OpenGlRenderer::reshape);
    glutKeyboardFunc(OpenGlRenderer::key);
    glutDisplayFunc(OpenGlRenderer::draw);
    glutVisibilityFunc(OpenGlRenderer::visible);
    glutMainLoop();    
}
