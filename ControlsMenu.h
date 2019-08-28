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
	bool config;
	
	int configNum;
	
	Texture configPrompt;
	
	const std::string controlFormat = "controlFormat.txt";
	
	const std::string controlConfig = "controlConfig.txt";

public:
	ControlsMenu();

	ControlsMenu(const ControlsMenu& orig);

	virtual ~ControlsMenu();
	
	

	std::string name();
	
	void render();
	
	void update();
	
	
	
	void controllerAxisHandler(SDL_Event e);
	
	void controllerButtonHandler(SDL_Event e);
	
	
	
	/*MENU FUNCTIONS*/
	void Config_buttons();
	void Set_button();
	void Default();
	void Back();
};

#endif /* CONTROLSMENU_H */

