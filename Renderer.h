#ifndef RENDERER_H
#define RENDERER_H
#include "View.h"

class Renderer : public Object{
public:
    virtual void run(ViewPtr view) = 0;
};

typedef boost::intrusive_ptr<Renderer> RendererPtr;
#endif
