/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OptionsMenu.h
 * Author: Clayton
 *
 * Created on August 25, 2019, 11:45 PM
 */

#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "MenuState.h"

class OptionsMenu: public MenuState{
private:

protected:

public:
	OptionsMenu();

	OptionsMenu(const OptionsMenu& orig);

	virtual ~OptionsMenu();
	
	
	
	std::string name();
	

	
	/*MENU FUNCTIONS*/
	void Change_controls();
	void Video_settings();
	void Audio_settings();
	//   Back = MenuState::back()
};

#endif /* OPTIONSMENU_H */

