/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StoryMenu.h
 * Author: Clayton
 *
 * Created on August 25, 2019, 11:44 PM
 */

#ifndef STORYMENU_H
#define STORYMENU_H

#include "MenuState.h"

class StoryMenu: public MenuState{
private:

protected:

public:
	StoryMenu();

	StoryMenu(const StoryMenu& orig);

	virtual ~StoryMenu();
	
	
	
	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Hold();
	void Back();
};

#endif /* STORYMENU_H */

