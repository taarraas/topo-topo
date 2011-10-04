/* 
 * File:   ViewParams.cpp
 * Author: vlad
 * 
 * Created on September 29, 2011, 1:09 PM
 */

#include "ViewParams.h"

ViewParams::ViewParams() {
    modelType = SOLID;
    faceCulling = false;
    showNormals = false;
}

ViewParams::ViewParams(const ViewParams& orig) {
}

ViewParams::~ViewParams() {
}

