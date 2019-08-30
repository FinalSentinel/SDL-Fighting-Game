/*
 * VersusState.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEENGINE_STATES_VERSUSSTATE_H_
#define GAMEENGINE_STATES_VERSUSSTATE_H_

#include "GameState.h"

//Max players in a single game.
const unsigned int ACTIVE_PLAYERS = 2;
//TODO resizing window
const int STAGE_WIDTH = 720;
const int STAGE_HEIGHT = 480;

class Player;
class SDL_Rect;

class VersusState : public GameState{
private:
    //static VersusState state;

    SDL_Rect* camera;

    Player* active[ACTIVE_PLAYERS];
	
	

protected:

//    VersusState() : camera(nullptr) {
//    };
//
//    virtual ~VersusState() {
//        delete camera;
//        camera = nullptr;
//    };

public:
    //static VersusState* instance();



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
