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

#include "GameEngine.h"

//struct iGameState{
//	
//	
//	
//	virtual void load() = 0;
//
//    virtual void pause(/*TODO*/) = 0;
//
//    virtual void render() = 0;
//
//    virtual void resume(/*TODO*/) = 0;
//
//    virtual void unload(/*TODO*/) = 0;
//
//    virtual void update() = 0;
//
//	
//	
//    //TODO event handler
//    void eventHandler(SDL_Event e);
//	
//    virtual void controllerAxisHandler(SDL_Event e) = 0;
//
//    virtual void controllerButtonHandler(SDL_Event e) = 0;
//
//    virtual void keyHandler(SDL_Event e) = 0;
//
//    //TODO generalized window handler???
//    virtual void windowHandler(SDL_Event e) = 0;
//};

class GameState/* : public iGameState*/{
protected:
    friend class GameEngine;
    static GameEngine* game;
	
	bool seen;
	
    GameState(): seen(true){};

    virtual ~GameState(){};

public:
//	static State* instance(){
//		static State state;
//		return &state;
//	}


	
	virtual bool get_seen();
	
    virtual void load() = 0;
	
	//FIXME ISO char* string
	virtual std::string name() = 0;

    virtual void pause(/*TODO*/) = 0;

    virtual void render() = 0;

    virtual void resume(/*TODO*/) = 0;
	
	virtual void set_seen(bool b);

    virtual void unload(/*TODO*/) = 0;

    virtual void update() = 0;


	
    //TODO event handler
    void eventHandler(SDL_Event e);
	
    virtual void controllerAxisHandler(SDL_Event e) = 0;

    virtual void controllerButtonHandler(SDL_Event e) = 0;

    virtual void keyHandler(SDL_Event e) = 0;

    //TODO generalized window handler???
    virtual void windowHandler(SDL_Event e) = 0;
};

#endif /* GAMEENGINE_GAMESTATE_H_ */

