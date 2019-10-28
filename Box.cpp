/*
 * Box.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: Clayton
 */

#include "Box.h"

 //TODO transparency option
int Box::aIn = 0x20;
int Box::aOut = 0xA0;



Box::Box(const int ax, const int ay, const int rx, const int ry, const int w, const int h, const SDL_Color color):
			rx(rx), ry(ry), rect({ax + rx, ay + ry, w, h}), color(color){
	//NONE
}

Box::~Box(void){
	//NONE
}

bool Box::collides(const Box b) const{
	return(rect.x	 < (b.get_x() + b.get_w()) &&
		   rect.y	 < (b.get_y() + b.get_h()) &&
		   b.get_x() < (rect.x	  + rect.w)	   &&
		   b.get_y() < (rect.y	  + rect.h)		 );
}

int Box::get_rx(void) const{
	return rx;
}

int Box::get_ry(void) const{
	return ry;
}

int Box::get_x(void) const{
	return rect.x;
}

int Box::get_y(void) const{
	return rect.y;
}

int Box::get_w(void) const{
	return rect.w;
}

int Box::get_h(void) const{
	return rect.h;
}

void Box::position(const int nx, const int ny){
	rect.x = nx + rx;
	rect.y = ny + ry;

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
