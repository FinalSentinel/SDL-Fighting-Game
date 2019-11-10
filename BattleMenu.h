/* 
 * File:   BattleMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 10:59 PM
 */

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "MenuState.h"



class BattleMenu: public MenuState{
private:
	//TODO lambdas?
	static void(BattleMenu::* const menuActions[])(void);

	static const std::string menuText[];

protected:
	enum Battle_Options{
		VERSUS,
		ARCADE,
		ONLINE,
		TRAINING,
		COMBO,
		TUTORIAL,
		BACK,
		numOptions
	};

public:
	BattleMenu(void);

	virtual ~BattleMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Char_select(void);
	//   Back = MenuState::back(void);

};

#endif /* BATTLEMENU_H */

