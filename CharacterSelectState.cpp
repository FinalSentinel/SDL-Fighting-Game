/* 
 * File:   CharacterSelectState.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 10:59 PM
 */

#include "CharacterSelectState.h"

#include "CharacterSelectMenu.h"
#include "VersusState.h"

CharacterSelectState::CharacterSelectState(const int vMode): mode(vMode){
    seen = false;
}

CharacterSelectState::~CharacterSelectState(void){
}

void CharacterSelectState::load(void){
    game->pushState(new CharacterSelectMenu(mode));

    return;
}

std::string CharacterSelectState::name(void) const{
    return "CharacterSelectState";
}

void CharacterSelectState::pause(void){
	//TODO

	return;
}

void CharacterSelectState::render(void) const{
	//TODO

	return;
}

void CharacterSelectState::resume(void){
	game->popState();

	return;
}

void CharacterSelectState::unload(void){
	//TODO

	return;
}

void CharacterSelectState::update(void){
	//TODO

	return;
}

void CharacterSelectState::controllerAxisHandler(void){
	//TODO

	return;
}

void CharacterSelectState::controllerButtonHandler(void){
	//TODO

	return;
}

void CharacterSelectState::keyHandler(void){
	//TODO

	return;
}

void CharacterSelectState::windowHandler(void){
	//TODO

	return;
}

/*MENU FUNCTIONS*/
