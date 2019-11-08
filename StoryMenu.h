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
	static const std::string menuText[];

	//TODO lambdas?
	static void(StoryMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Story_Options{
		STORY_STUFF,
		BACK,
		numOptions
	};

	StoryMenu(void);

	virtual ~StoryMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/

};

#endif /* STORYMENU_H */

