/* 
 * File:   MapParser.cpp
 * Author: taras
 * 
 * Created on September 28, 2011, 10:42 AM
 */

#include "MapParser.h"

MapParser::MapParser(std::string file)
    : ifstream(file.c_str()) {    
}

bool MapParser::next(MapElement& el) {
    if (ifstream.eof())
        return false;
    
    char type;
    ifstream >> type;
    
    switch (type) {
        case 'A' : {
            break;
        }
        default : {
            throw Exception("MapParser: Unknown edge type : " + type);
        }
    }
    
    return false;
}


