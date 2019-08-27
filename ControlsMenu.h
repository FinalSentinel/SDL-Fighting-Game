/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ControlsMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 11:50 PM
 */

#ifndef CONTROLSMENU_H
#define CONTROLSMENU_H

#include "MenuState.h"



class ControlsMenu: public MenuState{
private:

protected:

public:
	ControlsMenu();

	ControlsMenu(const ControlsMenu& orig);

	virtual ~ControlsMenu();
	
	

	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Back();
};

#endif /* CONTROLSMENU_H */

