/*
 * Player.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_PLAYER_H_
#define GAMEOBJECTS_PLAYER_H_

//TODO forward decl?
#include "SDL.h"

class Character;

class Player {
private:

public:
    //TODO private?
    //Controller ID
    SDL_GameController* controller;
    //Character selection
    Character* character;

    //TODO Bool for Controller/Keyboard

    Player(SDL_GameController* co = nullptr, Character* ch = nullptr) : controller(co), character(ch) {
    };

    virtual ~Player();

    //TODO Change character function
};

#endif /* GAMEOBJECTS_PLAYER_H_ */
