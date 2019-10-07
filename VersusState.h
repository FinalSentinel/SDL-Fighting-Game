/*
 * VersusState.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEENGINE_STATES_VERSUSSTATE_H_
#define GAMEENGINE_STATES_VERSUSSTATE_H_

#include "GameState.h"

enum Versus_Types{
	VERSUS,
	ONLINE,
	TRAINING,
	COMBO,
	TUTORIAL,
	ARCADE
};

//Max players in a single game.
const unsigned int ACTIVE_PLAYERS = 2;

//TODO Unit based stage/movement;
const int STAGE_WIDTH = 1280;
const int STAGE_HEIGHT = 720;

class Player;
class SDL_Rect;

class VersusState : public GameState{
private:
	int mode, level, music;
	
    SDL_Rect* camera;

    Player* active[ACTIVE_PLAYERS];
	

protected:

public:
    VersusState(int vMode, int vLevel, int vMusic);

    virtual ~VersusState();



    void decollide(Player* c1, Player* c2);

    void load();
	
	std::string name();

    void pause(/*TODO*/);

    void render();

    void resume(/*TODO*/);

    void unload(/*TODO*/);

    void update();



    //TODO event handler
    void controllerAxisHandler();

    void controllerButtonHandler();

    void keyHandler();

    void windowHandler();
};

#endif /* GAMEENGINE_STATES_VERSUSSTATE_H_ */
