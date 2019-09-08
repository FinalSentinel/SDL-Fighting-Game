/*
 * Entity.cpp
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#include "Entity.h"

Entity::Entity(int x, int y, bool left, int p): x(x), y(y), left(left), palette(p){
    //NONE
}

Entity::~Entity(){
    //NONE
}

bool Entity::get_left(){
    return left;
}

void Entity::set_left(bool l){
    left = l;

    return;
}
