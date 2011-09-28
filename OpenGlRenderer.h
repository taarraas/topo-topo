#ifndef OPEN_GL_RENDERER_H
#define OPEN_GL_RENDERER_H

#include "Renderer.h"
#include "View.h"

class OpenGlRenderer : public Renderer {
public:
    static ViewPtr view;
    
    static void reshape(int width, int height);

    static void key(unsigned char key, int x, int y);

    static void draw();
    static void idle();

    static void visible(int vis);
    
public:     
    virtual void run(ViewPtr view);      
};

#endif
