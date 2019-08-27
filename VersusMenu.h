/*
 * VersusMenu.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_MENUS_VERSUSMENU_H_
#define GAMEOBJECTS_MENUS_VERSUSMENU_H_

#include "MenuState.h"

enum Versus_Options{
	RETURN_TO_MENU,
	RESUME
};

enum Versus_Types{
	VERSUS,
	ARCADE,
	TRAINING,
	TUTORIAL,
	COMBO,
	ONLINE
};

class VersusMenu: public MenuState{
private:

protected:
	bool hide;

public:
	VersusMenu();

	virtual ~VersusMenu(){
	};

	//static VersusMenu* instance();
	
	
	
	void load();
	
	std::string name();
	
	void render();
	
	
	
	virtual void controllerButtonHandler(SDL_Event e);
	

	
	/*MENU FUNCTIONS*/
	void Return_to_menu();
	void Command_list();
	void Options();
	void Hide_menu();
	void Resume();
};

#endif /* GAMEOBJECTS_MENUS_VERSUSMENU_H_ */
