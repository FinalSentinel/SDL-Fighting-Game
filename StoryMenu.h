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
	//NONE

protected:
	//NONE

public:
	StoryMenu(void);

	virtual ~StoryMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Hold(void);
	//   Back = MenuState::back(void);

};

#endif /* STORYMENU_H */

