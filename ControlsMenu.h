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
#include "Player.h"



class ControlsMenu: public MenuState{
private:
    char hold[32];

protected:
//	int altSelection[game->MAX_PLAYERS];
//	
//	int altIndex[game->MAX_PLAYERS];
//	
//	//Tuple of menu option Text, Graphic, and Function
//	std::vector<std::tuple<std::string, Texture*, std::function<void()>>> altOptions[game->MAX_PLAYERS];
	
	bool config[MAX_PLAYERS];
	
	int configNum[MAX_PLAYERS];
	
	Texture prompt[MAX_PLAYERS];

public:
	static const char controlDefault[];
	
	static const char controlFormat[];
	
	
	ControlsMenu();

	virtual ~ControlsMenu();
	
	

	void setButton(Player* p, int n, std::string button);
	
	std::string name();
	
	void reload();
	
	void render();
	
	void update();
	
	
	
	void controllerAxisHandler();
	
	void controllerButtonHandler();
	
	
	
	/*MENU FUNCTIONS*/
	void Quick_config();
	void Default();
	//void back();
	void none();
};

#endif /* CONTROLSMENU_H */

