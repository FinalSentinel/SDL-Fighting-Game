/*
 * Box.cpp
 *
 *  Created on: Aug 8, 2019
 *      Author: Clayton
 */

#include "Box.h"

#include "GlobalInfo.h"

#include "Window.h"

 //TODO transparency option
int Box::aIn = 0x20;
int Box::aOut = 0xA0;



Box::Box(const int ax, const int ay, const int rx, const int ry, const int w, const int h, const SDL_Color color):
			rx(rx), ry(ry), color(color){
	rect = {ax + this->rx, ay + this->ry, w, h};
}

Box::~Box(void){
	//NONE
}

bool Box::collides(const Box b) const{
	return( rect.x	 < (b.get_x() + b.get_w()) &&
		    rect.y	 < (b.get_y() + b.get_h()) &&
		   b.get_x() < ( rect.x	  +  rect.w  ) &&
		   b.get_y() < ( rect.y	  +  rect.h  )	 );
}

int Box::get_rx(void) const{
	return rx;
}

int Box::get_ry(void) const{
	return ry + rect.h;
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

void Box::render(SDL_Renderer* renderer, Window* w, const bool side) const{
	SDL_Rect rendRect = rect;

	rendRect.x += STAGE_WIDTH / 2;
	rendRect.y  = STAGE_HEIGHT - rendRect.y - rendRect.h;

	if(!side){
		rendRect.x += WINDOW_REND_UNIT / 2;
	}
	rendRect.y += WINDOW_REND_UNIT / 2;

	rendRect.x /= WINDOW_REND_UNIT;
	rendRect.y /= WINDOW_REND_UNIT;
	rendRect.w /= WINDOW_REND_UNIT;
	rendRect.h /= WINDOW_REND_UNIT;

	rendRect.x += WINDOW_REND_X;
	rendRect.y += WINDOW_REND_Y;

    //Set passed renderer's draw color to Box fill draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, aIn);

    //Draw fill section of box
    SDL_RenderFillRect(renderer, &rendRect);

    //Set passed renderer's draw color to Box outline draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, aOut);

    //Draw outline
    SDL_RenderDrawRect(renderer, &rendRect);

    return;
}
