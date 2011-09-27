/* 
 * File:   Object.h
 * Author: taras
 *
 * Created on September 27, 2011, 10:56 AM
 */

#ifndef OBJECT_H
#define	OBJECT_H

#include <boost/intrusive_ptr.hpp>

class Object {
public:
    Object() : refcount_(0) { };
    virtual ~Object() { };

    friend void intrusive_ptr_add_ref(Object * x) {
        x->refcount_++;
    }

    friend void intrusive_ptr_release(Object * x) {
        if (x->refcount_-- == 1) {            
            delete x;
        }
    }
private:
    int refcount_;
};

#endif	/* OBJECT_H */

