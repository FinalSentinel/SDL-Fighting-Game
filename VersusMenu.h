/*
 * VersusMenu.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#ifndef VERSUSMENU_H_
#define VERSUSMENU_H_

#include "MenuState.h"

class VersusState;

class VersusMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(VersusMenu::* const menuActions[])(void);

	VersusState* vstate;

protected:
	bool hide;

public:
	enum Versus_Options{
		RESUME,
		COMBO_LIST,
		DEMO,
		COMMAND_LIST,
		TRAINING_OPTIONS,
		OPTIONS,
		HIDE_MENU,
		RETURN_TO_LOBBY,
		RETURN_TO_MAIN_MENU,
		numOptions
	};

	VersusMenu(VersusState* versus);

	virtual ~VersusMenu(void);
	
	void load(void);
	
	std::string name(void) const;
	
	void render(void) const;
	
	virtual void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	//   Resume = MenuState::back(void){
	void Command_list(void);
	void Training_options(void);
	void Options(void);
	void Hide_menu(void);
	void Return_to_menu(void);

};

#endif /* VERSUSMENU_H_ */
