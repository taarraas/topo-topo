/* 
 * File:   CameraState.h
 * Author: vlad
 *
 * Created on September 29, 2011, 1:38 PM
 */

#ifndef CAMERASTATE_H
#define	CAMERASTATE_H

#include "Core.h"

class CameraState {
public:
    CameraState();
    CameraState(const CameraState& orig);
    virtual ~CameraState();
    
    virtual void mouseMovement(float dx, float dy);
    virtual void go(float v, float xangle, float yangle);
    virtual void goForward(float v);
    virtual void goBackward(float v);
    virtual void goLeft(float v);
    virtual void goRight(float v);
    
    Point pos;
    float xrot, yrot;
private:
};

#endif	/* CAMERASTATE_H */

