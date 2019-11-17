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



class Player {
private:
	//TODO cleanup

protected:
	//NONE

public:
	enum versusActions{
		INVALID_CONTROL = -1,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		PUNCH,
		KICK,
		HEAVY,
		SPECIAL,
		TAUNT,
		P_K,
		P_S,
		K_H,
		P_K_H,
		P_K_H_S,
		RECORD,
		PLAY,
		RESET,
		PAUSE,
		num_versusActions
	};

	static const char controlConfig[];
	
	static const char controlDefault[];
	
    //TODO private?
	int playerNum;
    //Controller ID
    SDL_GameController* controller;

    //Character selection
    Character* character;
	CharacterID charID;
	
	int controls[SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX];

    //TODO Bool for Controller/Keyboard
	
    Player(int num, SDL_GameController* co = nullptr, Character* ch = nullptr);

    virtual ~Player();

    //TODO Change character function
	CharacterID get_character() const;
	
	void saveControls() const;
	
	int setButton(int action, int button);

	void set_character(CharacterID ch);

};

#endif /* PLAYER_H */
