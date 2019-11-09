/*
 * Entity.cpp
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#include "Entity.h"

#include "Window.h"

Entity::Entity(const int x, const int y, const int dx, const int dy, const bool left, const int p):
				x(x), y(y), dx(dx), dy(dy), left(left), palette(p){
	//NONE
}

Entity::~Entity(void){
	//NONE
}

void Entity::addBox(const BoxType type, const int rx, const int ry, const int w, const int h){
	SDL_Color c;
	switch(type){
		case(COLLISION):{
			c = {0xFF, 0xFF, 0x00};
		}
		break;

		case(HURT):{
			c = {0x00, 0xFF, 0x00};
		}
		break;

		case(HIT):{
			c = {0xFF, 0x00, 0x00};
		}
		break;

		default:{
			c = {0xFF, 0xFF, 0xFF};
		}
		break;
	}
	boxes[type].emplace_back(Box(x, y, rx, ry, w, h, c));

	return;
}

int Entity::get_x(void) const{
	return x;
}

int Entity::get_y(void) const{
	return y;
}

int Entity::get_dx(void) const{
	return dx;
}

int Entity::get_dy(void) const{
	return dy;
}

bool Entity::get_left(void) const{
	return left;
}

std::vector<Box> Entity::getBoxes(const BoxType type) const{
	return boxes[type];
}

void Entity::move(void){
	position(x + dx, y + dy);

	return;
}

void Entity::position(const int nx, const int ny){
	x   = nx;

	y   = ny * (ny >= 0);
	dy *= (ny >= 0);

	for(int type = 0; type < BoxTypeNum; type++){
		for(unsigned int i = 0; i < boxes[type].size(); i++){
			boxes[type][i].position(x, y);
		}
	}

	return;
}

void Entity::render(Window* w, const bool side) const{
	for(int type = 0; type < BoxTypeNum; type++){
		for(unsigned int i = 0; i < boxes[type].size(); i++){
			boxes[type][i].render(w, side);
		}
	}

	return;
}

void Entity::set_dx(const int ndx){
	dx = ndx;

	return;
}

void Entity::set_dy(const int ndy){
	dy = ndy;

	return;
}

void Entity::set_left(const bool l){
	left = l;

	return;
}
