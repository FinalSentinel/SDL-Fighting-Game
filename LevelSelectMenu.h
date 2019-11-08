/* 
 * File:   LevelSelectMenu.h
 * Author: Clayton
 *
 * Created on October 2, 2019, 1:41 AM
 */

#ifndef LEVELSELECTMENU_H
#define LEVELSELECTMENU_H

#include "MenuState.h"



class LevelSelectMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(LevelSelectMenu::* const menuActions[])(void);

	int mode;

protected:
	//NONE

public:
	enum LevelSelect_Options{
		LEVEL_1,
		LEVEL_2,
		LEVEL_3,
		LEVEL_4,
		LEVEL_5,
		LEVEL_6,
		BACK,
		numOptions
	};

	LevelSelectMenu(int vMode);

	~LevelSelectMenu(void);
	
	std::string name(void) const;

	/*MENU FUNCTIONS*/
	void Set_level(void);

};

#endif /* LEVELSELECTMENU_H */

