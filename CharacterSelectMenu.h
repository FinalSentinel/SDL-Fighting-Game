/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterSelectMenu.h
 * Author: Clayton
 *
 * Created on September 23, 2019, 7:47 PM
 */

#ifndef CHARACTERSELECTMENU_H
#define CHARACTERSELECTMENU_H

#include "MenuState.h"



enum StageSetting{
	LEVEL,
	MUSIC
};

class CharacterSelectMenu: public MenuState{
private:

protected:
	int mode;
	
	bool selected[2];

public:
	CharacterSelectMenu(int vMode);

	virtual ~CharacterSelectMenu();
	
	
	
	void load();
	
	std::string name();
	
	void resume();
	
	void update();
	
	
	
	/*MENU FUNCTIONS*/
	void Set_character();
};

#endif /* CHARACTERSELECTMENU_H */

