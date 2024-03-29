#ifndef VIEW_H
#define VIEW_H

#include "Object.h"
#include <boost/intrusive_ptr.hpp>

class View : public Object {
public:
    virtual void init() = 0;
    virtual void reshape(int width, int height) = 0;

    virtual void key(unsigned char key, int x, int y);

    virtual void draw() = 0;
    virtual void idle() = 0;
    virtual void mouse(int button, int state, int x, int y);
    virtual void motion(int x, int y); 
};

typedef boost::intrusive_ptr<View> ViewPtr;

#endif
