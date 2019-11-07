/*
 * GameState.h
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

//XXX
#include <iostream>
#include <sstream>

#include "GameEngine.h"
#include "SDL.h"
#include "SDL_mixer.h"

class GameState{
private:
	//NONE

protected:
    friend class GameEngine;

    static GameEngine* game;
	
	bool seen;

public:
	GameState(void);

	virtual ~GameState(void);

	virtual bool get_seen(void) const;
	
    virtual void load(void) = 0;
	
	virtual std::string name(void) const = 0;

    virtual void pause(/*TODO*/) = 0;

    virtual void render(void) const = 0;

    virtual void resume(/*TODO*/) = 0;
	
	virtual void set_seen(bool b);

    virtual void unload(/*TODO*/) = 0;

    virtual void update(void) = 0;
	
    //TODO event handler
    void eventHandler(void);
	
    virtual void controllerAxisHandler(void) = 0;

    virtual void controllerButtonHandler(void) = 0;

    virtual void keyHandler(void) = 0;

    //TODO generalized window handler???
    virtual void windowHandler(void) = 0;

};

#endif /* GAMESTATE_H */

