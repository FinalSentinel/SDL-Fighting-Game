/*
 * MenuState.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

//TODO reorganize menu loading/pushing/popping/etc structure

#ifndef GAMEENGINE_GAMESTATES_MENUSTATE_H_
#define GAMEENGINE_GAMESTATES_MENUSTATE_H_

#include <functional>
#include <vector>

//XXX
#include <iostream>

#include "GameState.h"

#include "Texture.h"

const int MAX_MENU_SIZE = 10;

class MenuState : public GameState{
protected:
	int flag = -1;
	
    int selection = 0;
	
	int index = 0;
	
	//XXX
	int numSelections;

	//TODO stringstreams
	std::vector<std::string> options;
	std::vector<std::function<void()> > actions;
	//TODO objects
	std::vector<Texture*> buttons;
	
//  std::vector<std::string> options;
//	
//	std::vector<std::function<void()> > actions;
//	
//	std::vector<Texture*> buttons;

public:
    MenuState();
	
    virtual ~MenuState();

    //MenuState* instance();

	
	
	virtual void callAction();
	
	virtual void close();
	
    virtual void load();
	
	virtual std::string name() = 0;

    virtual void pause(/*TODO*/);
	
    virtual void render();

    virtual void resume(/*TODO*/);

    virtual void unload(/*TODO*/);

    virtual void update();



    //TODO event handler
    virtual void controllerAxisHandler(SDL_Event e);

    virtual void controllerButtonHandler(SDL_Event e);

    virtual void keyHandler(SDL_Event e);

    //TODO generalized window handler???
    virtual void windowHandler(SDL_Event e);
};

#endif /* GAMEENGINE_GAMESTATES_MENUSTATE_H_ */
