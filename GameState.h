/*
 * GameState.h
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#ifndef GAMEENGINE_GAMESTATE_H_
#define GAMEENGINE_GAMESTATE_H_

//XXX
#include <iostream>

#include "SDL.h"
#include "SDL_mixer.h"

#include <sstream>

#include "GameEngine.h"



class GameState{
protected:
    friend class GameEngine;
    static GameEngine* game;
	
	bool seen;
	
    GameState(): seen(true){};

    virtual ~GameState(){};

public:	
	virtual bool get_seen();
	
    virtual void load() = 0;
	
	virtual std::string name() = 0;

    virtual void pause(/*TODO*/) = 0;

    virtual void render() = 0;

    virtual void resume(/*TODO*/) = 0;
	
	virtual void set_seen(bool b);

    virtual void unload(/*TODO*/) = 0;

    virtual void update() = 0;


	
    //TODO event handler
    void eventHandler();
	
    virtual void controllerAxisHandler() = 0;

    virtual void controllerButtonHandler() = 0;

    virtual void keyHandler() = 0;

    //TODO generalized window handler???
    virtual void windowHandler() = 0;
};

#endif /* GAMEENGINE_GAMESTATE_H_ */

