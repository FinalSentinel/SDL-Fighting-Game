/*
 * Entity.cpp
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#include "Entity.h"

Entity::~Entity(){
}

bool Entity::get_left(){
    return left;
}

void Entity::set_left(bool l){
    left = l;

    return;
}
