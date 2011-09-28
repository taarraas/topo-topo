#ifndef RENDERER_H
#define RENDERER_H
#include "View.h"

class Renderer {
public:
    virtual void run(ViewPtr view) = 0;
};
#endif
