/* 
 * File:   MapParser.h
 * Author: taras
 *
 * Created on September 28, 2011, 10:42 AM
 */

#ifndef MAPPARSER_H
#define	MAPPARSER_H

#include "Core.h"
#include <fstream>
class MapParser {
public:
    struct MapElement {
        Point from;
        Point to;     
        MapElement() : from(Point()), to(Point()) { };
        MapElement(Point from, Point to) : from(from), to(to) { };
    };
    MapParser(std::string file);
    bool next(MapElement& el);
private:
    std::ifstream ifstream;
};

#endif	/* MAPPARSER_H */

