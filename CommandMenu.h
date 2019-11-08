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
	static const std::string menuText[];

	//TODO lambdas?
	static void(CommandMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Command_Options{
		CHARACTER_NAME,
		MOVE_1,
		MOVE_2,
		MOVE_3,
		BACK,
		numOptions
	};

	CommandMenu(void);

	virtual ~CommandMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Play(void);
	//   Back = MenuState::back(void);
	void none(void);

};

#endif /* COMMANDMENU_H */
