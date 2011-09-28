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
    char type = ' ';
    while ( (ifstream >> type) && (type < 'A' || type > 'Z') ) {
    }

    if (ifstream.eof())
        return false;
        
    switch (type) {
        case 'A' : {
            float x, y, z;
            ifstream >> x >> y >> z;
            el.from = Point(x, y, z);
            ifstream >> x >> y >> z;
            el.to = Point(x, y, z);
            break;
        }
        default : {
            throw Exception("MapParser: Unknown edge type : " + type);
        }
    }
    
    return !ifstream.eof();
}


