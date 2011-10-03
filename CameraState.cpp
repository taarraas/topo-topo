/* 
 * File:   CameraState.cpp
 * Author: vlad
 * 
 * Created on September 29, 2011, 1:38 PM
 */

#include "CameraState.h"
#include "Geometry.h"

CameraState::CameraState() {
    xrot = yrot = 0;
    pos = Point(0, 0, 0);
}

CameraState::CameraState(const CameraState& orig) {
}

CameraState::~CameraState() {
}

void CameraState::mouseMovement(float dx, float dy) {
    if (xrot < 270 && xrot > 90) {
        xrot += dy;    
        yrot -= dx;                
    } else {
        xrot += dy;    
        yrot += dx;        
    }
    if (xrot > 360) xrot -= 360;
    if (yrot > 360) yrot -= 360;
    if (xrot < 0) xrot += 360;
    if (yrot < 0) yrot += 360;
}

void CameraState::goForward(float v) {
    go (v, xrot, yrot);
}

void CameraState::goBackward(float v) {
    go (-v, xrot, yrot);
}

void CameraState::goLeft(float v) {
    float xangle_rad = Geometry::radian(xrot);
    float yangle_rad = Geometry::radian(yrot);
    
    pos.x -= v * cos(yangle_rad);
    pos.z -= v * sin(yangle_rad);
}

void CameraState::goRight(float v) {
    float xangle_rad = Geometry::radian(xrot);
    float yangle_rad = Geometry::radian(yrot);
    
    pos.x += v * cos(yangle_rad);
    pos.z += v * sin(yangle_rad);
}

void CameraState::go(float v, float xangle, float yangle) {
    float xangle_rad = Geometry::radian(xangle);
    float yangle_rad = Geometry::radian(yangle);
    
    float sign = 1;
    if (xrot < 270 && xrot > 90)
        sign = -1;
    
    pos.x += v * sin(yangle_rad) * sign;
    pos.z -= v * cos(yangle_rad) * sign;
    pos.y -= v * sin(xangle_rad);        
}
