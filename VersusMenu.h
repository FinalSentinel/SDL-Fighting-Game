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

class VersusMenu: public MenuState{
private:
	int mode;

protected:
	bool hide;

public:
	VersusMenu(int vMode);

	virtual ~VersusMenu();
	
	
	
	void load();
	
	std::string name();
	
	void render();
	
	
	
	virtual void controllerButtonHandler();
	

	
	/*MENU FUNCTIONS*/
	//   Resume = MenuState::back()
	void Command_list();
	void Options();
	void Hide_menu();
	void Return_to_menu();
};

#endif /* GAMEOBJECTS_MENUS_VERSUSMENU_H_ */
