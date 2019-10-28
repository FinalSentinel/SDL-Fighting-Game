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
	//NONE

protected:
	//NONE

public:
	BattleMenu(void);

	virtual ~BattleMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Char_select(void);
	//   Back = MenuState::back(void);

};

#endif /* BATTLEMENU_H */

