/* 
 * File:   MusicSelectMenu.h
 * Author: Clayton
 *
 * Created on October 7, 2019, 12:44 AM
 */

#ifndef MUSICSELECTMENU_H
#define MUSICSELECTMENU_H

#include "MenuState.h"



class MusicSelectMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(MusicSelectMenu::* const menuActions[])(void);

	int mode, level;

protected:
	//NONE

public:
	enum MusicSelect_Options{
		SONG_1,
		SONG_2,
		SONG_3,
		SONG_4,
		SONG_5,
		SONG_6,
		BACK,
		numOptions
	};

	MusicSelectMenu(int vMode, int vLevel);

	virtual ~MusicSelectMenu(void);
	
	std::string name(void) const;

	/*MENU FUNCTIONS*/
	void Set_music(void);

};

#endif /* MUSICSELECTMENU_H */

