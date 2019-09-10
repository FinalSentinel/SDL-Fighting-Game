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
//XXX
#include <iostream>
#include <tuple>
#include <vector>

#include "GameState.h"
#include "Texture.h"

enum Option_Structure{
	TEXT,
	GRAPHIC,
	FUNCTION
};

const int MAX_MENU_SIZE = 10;



class SFX;

class MenuState: public GameState{
private:
	
protected:
	static const char menuClick[];
	static SFX* menuClickSFX;
	
	int flag = -1;
	
    int selection = 0;
	
	int index = 0;

	//Tuple of menu option Text, Graphic, and Function
	std::vector<std::tuple<std::string, Texture*, std::function<void()>>> options;

public:
    MenuState();
	
    virtual ~MenuState();

	
	
	virtual void callAction();
	
	virtual void back();
	
	virtual void close();
	
    virtual void load();
	
	virtual std::string name() = 0;

    virtual void pause(/*TODO*/);
	
    virtual void render();

    virtual void resume(/*TODO*/);
	
	//Returns to top of menu.
	void returnToTop();

    virtual void unload(/*TODO*/);

    virtual void update();



    //TODO event handler
    virtual void controllerAxisHandler();

    virtual void controllerButtonHandler();

    virtual void keyHandler();

    //TODO generalized window handler???
    virtual void windowHandler();
};

#endif /* GAMEENGINE_GAMESTATES_MENUSTATE_H_ */
