/*
 * Character.cpp
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#include "Character.h"

Character::Character(const CharacterID id, const int x, const int y, const bool l, const int p, const int hp, const int sp):
						charID(id), Entity(x, y, 0, 0, l, p), health(hp), meter(sp){
	wall = false;
}

Character::~Character(void){
	//NONE
}
	
CharacterID Character::get_id(void) const{
    return charID;
}

bool Character::get_wall(void) const{
	return wall;
}

//TODO update later
//TODO check against other input handlers
void Character::handleEvent(SDL_Event* e){
	if((e->type == SDL_KEYDOWN || e->type == SDL_KEYUP) && e->key.repeat == 0){
		if(e->type == SDL_KEYDOWN){
			//Adjust the velocity
			switch(e->key.keysym.sym){
				case SDLK_w:{
					dy -= 10;
				}break;

				case SDLK_s:{
					dy += 10;
				}break;

				case SDLK_a:{
					dx -= 10;
				}break;

				case SDLK_d:{
					dx += 10;
				}break;
			}
		}
		//If a key was released
		else if(e->type == SDL_KEYUP){
			//Adjust the velocity
			switch(e->key.keysym.sym){
				case SDLK_w:{
					dy += 10;
				}break;

				case SDLK_s:{
					dy -= 10;
				}break;

				case SDLK_a:{
					dx += 10;
				}break;

				case SDLK_d:{
					dx -= 10;
				}break;
			}
		}
	}

	return;
}

void Character::set_wall(const bool w){
	wall = w;

	return;
}