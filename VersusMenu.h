/*
 * VersusMenu.h
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#ifndef VERSUSMENU_H_
#define VERSUSMENU_H_

#include "MenuState.h"

enum Versus_Options{
	RETURN_TO_MENU,
	RESUME
};

class VersusMenu: public MenuState{
private:
	int mode;

protected:
	bool hide;

public:
	VersusMenu(int vMode);

	virtual ~VersusMenu(void);
	
	void load(void);
	
	std::string name(void) const;
	
	void render(void) const;
	
	virtual void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	//   Resume = MenuState::back(void){
	void Command_list(void);
	void Options(void);
	void Hide_menu(void);
	void Return_to_menu(void);

};

#endif /* VERSUSMENU_H_ */
