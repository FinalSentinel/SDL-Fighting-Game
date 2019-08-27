/*
 * Character.cpp
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#include "Character.h"

#include "Box.h"

Character::~Character(){
}

void Character::addColBox(int ax, int ay, int w, int h){
    collisionBoxes.push_back(new Box(x, y, ax, ay, w, h,{0xFF, 0xFF, 0x00}));

    return;
}

int Character::get_x(){
    return x;
}

int Character::get_y(){
    return y;
}

int Character::get_dx(){
    return dx;
}

int Character::get_dy(){
    return dy;
}

std::vector<Box*> Character::getColBoxes(){
    return collisionBoxes;
}

void Character::move(int nx, int ny){
    //Move to specified position.
    x = nx;
    y = ny;

    //NOTE Check index vs iterator differences
    //Move boxes to new position.
    for(unsigned int i = 0; i < collisionBoxes.size(); i++){
        //TODO
        collisionBoxes[i]->move(x + collisionBoxes[i]->get_ax(), y + collisionBoxes[i]->get_ay());
    }

    return;
}

void Character::render(SDL_Renderer* renderer) const{
    //TODO render sprites
    for(unsigned int i = 0; i < collisionBoxes.size(); i++){
        collisionBoxes[i]->render(renderer);
    }

    return;
}

void Character::set_dx(int i){
    dx = i;

    return;
}

void Character::set_dy(int i){
    dy = i;

    return;

}

void Character::update(){
    //Else momentum based movement.
    x += dx;
    y += dy;

    //NOTE Check index vs iterator differences
    //Move boxes to new position.
    for(unsigned int i = 0; i < collisionBoxes.size(); i++){
        //TODO
        collisionBoxes[i]->move(x + collisionBoxes[i]->get_ax(), y + collisionBoxes[i]->get_ay());
    }

    return;
}
