//
// Created by grusted on 12/11/24.
//

#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include "map.h"

namespace GeneticThings {
    enum ObjectType {
        EMPTY,
        WALL,
        ROBOT,
        FOOD
      };

    class Map;

    class MapObject {
    protected:
        int x;
        int y;
        ObjectType type;
        Map *map;
    public:
        MapObject();
        MapObject(int x, int y, Map* map, ObjectType type = EMPTY);
        ~MapObject();
    };
}


#endif //MAPOBJECT_H
