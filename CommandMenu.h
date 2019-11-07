/* 
 * File:   CommandMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 9:53 PM
 */

#ifndef COMMANDMENU_H
#define COMMANDMENU_H

#include "MenuState.h"

class CommandMenu: public MenuState{
private:
	//NONE

protected:
	//NONE

public:
	CommandMenu(void);

	virtual ~CommandMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Play(void);
	//   Back = MenuState::back(void);
	void none(void) const;

};

#endif /* COMMANDMENU_H */

