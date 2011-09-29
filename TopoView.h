#ifndef TOPO_VIEW_H
#define TOPO_VIEW_H

#include "Core.h"
#include "View.h"
#include "ViewParams.h"
#include "ViewState.h"
#include "CameraState.h"

class TopoView : public View {    
public:
    virtual void init();
    virtual void reshape(int width, int height);
    virtual void key(unsigned char key, int x, int y);    
    virtual void draw();
    virtual void idle();   
    virtual void mouse(int button, int state, int x, int y);
    virtual void motion(int x, int y);   
    
    void setModelType(ViewParams::ModelType modelType);
    void setFaceCulling(bool faceCulling);
    
    TopoView(const std::vector<Triangle> & triangles);
    
private:   
    ViewParams params;
    ViewState viewState;
    CameraState cameraState;
    const std::vector<Triangle> & triangles_;
};

#endif
