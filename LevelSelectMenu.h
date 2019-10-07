/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelSelectMenu.h
 * Author: Clayton
 *
 * Created on October 2, 2019, 1:41 AM
 */

#ifndef LEVELSELECTMENU_H
#define LEVELSELECTMENU_H

#include "MenuState.h"

enum levelList{
	error_level = -1,
	LEVEL_1,
	LEVEL_2,
	LEVEL_3,
	LEVEL_4,
	LEVEL_5,
	LEVEL_6,
	levelNum
};

const std::string LEVEL_LIST[levelNum] = {
	"Level 1",
	"Level 2",
	"Level 3",
	"Level 4",
	"Level 5",
	"Level 6"
};

class LevelSelectMenu: public MenuState{
private:
	int mode;

protected:

public:
	LevelSelectMenu(int vMode);

	virtual ~LevelSelectMenu();
	
	
	
	std::string name();



	/*MENU FUNCTIONS*/
	void Set_level();
};

#endif /* LEVELSELECTMENU_H */

