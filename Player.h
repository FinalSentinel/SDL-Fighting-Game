/*
 * Player.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_PLAYER_H_
#define GAMEOBJECTS_PLAYER_H_

#include <string>

#include "SDL.h"

enum versusControls{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	PUNCH,
	KICK,
	HEAVY,
	SPECIAL,
	TAUNT,
	PK,
	PS,
	KH,
	PKH,
	PKHS,
	RECORD,
	PLAY,
	RESET,
	PAUSE,
	versusControlsNum
};

class Character;

class Player {
private:

public:
	static const char controlConfig[];
	
	static const char controlDefault[];
	
    //TODO private?
	int playerNum;
    //Controller ID
    SDL_GameController* controller;
    //Character selection
    Character* character;
	int charID;
	
	std::string controls[versusControlsNum];

    //TODO Bool for Controller/Keyboard
	
	

    Player(int num, SDL_GameController* co = nullptr, Character* ch = nullptr);

    virtual ~Player();

	
	
    //TODO Change character function
	int get_character();
	
	void saveControls();
	
	void set_character(int ch);
};

#endif /* GAMEOBJECTS_PLAYER_H_ */
