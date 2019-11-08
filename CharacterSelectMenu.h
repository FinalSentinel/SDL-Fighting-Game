/* 
 * File:   CharacterSelectMenu.h
 * Author: Clayton
 *
 * Created on September 23, 2019, 7:47 PM
 */

#ifndef CHARACTERSELECTMENU_H
#define CHARACTERSELECTMENU_H

#include "MenuState.h"



class CharacterSelectMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(CharacterSelectMenu::* const menuActions[])(void);

	int mode;
	
	bool selected[2];

protected:
	//NONE

public:
	enum CharacterSelect_Options{
		CHAR_1,
		CHAR_2,
		CHAR_3,
		CHAR_4,
		CHAR_5,
		LAMBDA,
		BACK,
		numOptions
	};

	CharacterSelectMenu(int vMode);

	virtual ~CharacterSelectMenu(void);
	
	void load(void);
	
	std::string name(void) const;
	
	void resume(void);
	
	void update(void);
	
	/*MENU FUNCTIONS*/
	void Set_character(void);

};

#endif /* CHARACTERSELECTMENU_H */

