/* 
 * File:   ViewParams.h
 * Author: vlad
 *
 * Created on September 29, 2011, 1:09 PM
 */

#ifndef VIEWPARAMS_H
#define	VIEWPARAMS_H

#include "Core.h"

class ViewParams: public Object {
public:
    enum ModelType {SOLID, WIRE};
    
    ViewParams();
    ViewParams(const ViewParams& orig);
    virtual ~ViewParams();
    
    ModelType modelType;
    bool faceCulling;
};

#endif	/* VIEWPARAMS_H */

