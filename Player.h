/*
 * Player.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Clayton
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "Character.h"
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

class Player {
private:
	//TODO cleanup

protected:
	//NONE

public:
	static const char controlConfig[];
	
	static const char controlDefault[];
	
    //TODO private?
	int playerNum;
    //Controller ID
    SDL_GameController* controller;

    //Character selection
    Character* character;
	CharacterID charID;
	
	std::string controls[versusControlsNum];

    //TODO Bool for Controller/Keyboard
	
    Player(int num, SDL_GameController* co = nullptr, Character* ch = nullptr);

    virtual ~Player();

    //TODO Change character function
	CharacterID get_character() const;
	
	void saveControls() const;
	
	void set_character(CharacterID ch);

};

#endif /* PLAYER_H */
