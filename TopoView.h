#ifndef TOPO_VIEW_H
#define TOPO_VIEW_H

#include "Core.h"
#include "View.h"

class TopoView : public View {    
public:
    virtual void init();
    virtual void reshape(int width, int height);
    virtual void key(unsigned char key, int x, int y);    
    virtual void draw();
    virtual void idle();   
       
    TopoView(const std::vector<Triangle> & triangles);
    
private:   
    const std::vector<Triangle> & triangles_;    
    float rot;
    bool wire_;
    bool faceCulling_;
};

#endif
