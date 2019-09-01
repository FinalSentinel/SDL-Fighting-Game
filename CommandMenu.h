/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 9:53 PM
 */

#ifndef COMMANDMENU_H
#define COMMANDMENU_H

#include "MenuState.h"

class CommandMenu: public MenuState{
private:

protected:

public:
	CommandMenu();

	CommandMenu(const CommandMenu& orig);

	virtual ~CommandMenu();
	
	
	
	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Play();
	//   Back = MenuState::back()
	void none();
};

#endif /* COMMANDMENU_H */

