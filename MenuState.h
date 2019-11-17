/*
 * MenuState.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

//TODO reorganize menu loading/pushing/popping/etc structure

#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include <functional>
//XXX
#include <iostream>
#include <tuple>
#include <vector>

#include "GameState.h"
#include "Texture.h"

enum Option_Structure{
	TEXT,
	TEXTURE,
	FUNCTION
};

const int MAX_MENU_SIZE = 10;

class SFX;

class MenuState: public GameState{
private:
	//NONE
	
protected:
	static const char menuClick[];
	static SFX* menuClickSFX;
	
	int flag = -1;
	
    int selection = 0;
	
	unsigned int index = 0;

	//TODO proper Option class.
	//Tuple of menu option Text, Graphic, and Function
	std::vector<std::tuple<std::string, Texture*, std::function<void(void)>>> options;

public:
    MenuState(void);
	
    virtual ~MenuState(void);
	
	virtual void callAction(void) const;
	
	virtual void back(void);
	
	virtual void close(void);
	
    virtual void load(void);
	
	virtual std::string name(void) const = 0;

    virtual void pause(void);
	
    virtual void render(void) const;

    virtual void resume(void);
	
	//Returns to top of menu.
	void returnToTop(void);

    virtual void unload(void);

    virtual void update(void);

    //TODO event handler
    virtual void controllerAxisHandler(void);

    virtual void controllerButtonHandler(void);

    virtual void keyHandler(void);

    //TODO generalized window handler???
    virtual void windowHandler(void);
	
	/*MENU FUNCTION TEMP*/
	void TEMP(void);

};

#endif /* MENUSTATE_H */
