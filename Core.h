/* 
 * File:   Core.h
 * Author: taras
 *
 * Created on September 27, 2011, 9:44 AM
 */

#ifndef CORE_H
#define	CORE_H

#include <memory>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <boost/intrusive_ptr.hpp>
#include <boost/foreach.hpp>
#include "Object.h"
#include "Primitives.h"
#include "Shape.h"
#include <iostream>

#define LOG_INFO (std::cout << std::endl)

struct Exception {
    std::string message;
    Exception(std::string msg) : message(msg) { };
};

#endif	/* CORE_H */

