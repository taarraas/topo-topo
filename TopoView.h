#ifndef TOPO_VIEW_H
#define TOPO_VIEW_H

#include "View.h"

class TopoView : public View {
    float rtri;
public:
    virtual void init();
    virtual void reshape(int width, int height);
    virtual void key(unsigned char key, int x, int y);    
    virtual void draw();
    virtual void idle();   
};

#endif
