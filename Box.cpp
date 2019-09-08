/*
 * Box.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: Clayton
 */

#include "Box.h"

#include "SDL_image.h"

//TODO transparency option
Uint8 Box::aIn = 0x20;
Uint8 Box::aOut = 0xA0;

Box::Box(int x, int y, int ax, int ay, int w, int h, SDL_Color color):
ax(ax), ay(ay), rect({x + ax, y + ay, w, h}), color(color){
    //NONE
    
}

Box::~Box(){
    //NONE
}



bool Box::collide(Box* b) const{
    return(rect.x < b->get_x() + b->get_w() &&
            rect.y < b->get_y() + b->get_h() &&
            b->get_x() < rect.x + rect.w &&
            b->get_y() < rect.y + rect.h);
}

int Box::get_x() const{
    return rect.x;
}

int Box::get_y() const{
    return rect.y;
}

int Box::get_w() const{
    return rect.w;
}

int Box::get_h() const{
    return rect.h;
}

int Box::get_ax() const{
    return ax;
}

int Box::get_ay() const{
    return ay;
}

void Box::move(int x, int y){
    //Move to Entity's position shifted by anchor point.
    rect.x = x + ay;
    rect.y = y + ay;

    return;
}

void Box::render(SDL_Renderer* renderer) const{
    //Set passed renderer's draw color to Box fill draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, aIn);

    //Draw fill section of box
    SDL_RenderFillRect(renderer, &rect);

    //Set passed renderer's draw color to Box outline draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, aOut);

    //Draw outline
    SDL_RenderDrawRect(renderer, &rect);

    return;
}
