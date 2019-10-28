/* 
 * File:   CharacterSelectMenu.h
 * Author: Clayton
 *
 * Created on September 23, 2019, 7:47 PM
 */

#ifndef CHARACTERSELECTMENU_H
#define CHARACTERSELECTMENU_H

#include "MenuState.h"

enum CharacterList{
	error_character = -1,
	CHAR_1,
	CHAR_2,
	CHAR_3,
	CHAR_4,
	CHAR_5,
	LAMBDA,
	charNum
};

const std::string CHARACTER_LIST[charNum] = {
	"Character 1",
	"Character 2",
	"Character 3",
	"Character 4",
	"Character 5",
	"Lambda"
};

class CharacterSelectMenu: public MenuState{
private:
	int mode;
	
	bool selected[2];

protected:
	//NONE

public:
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

