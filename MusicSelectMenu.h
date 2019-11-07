/* 
 * File:   MusicSelectMenu.h
 * Author: Clayton
 *
 * Created on October 7, 2019, 12:44 AM
 */

#ifndef MUSICSELECTMENU_H
#define MUSICSELECTMENU_H

#include "MenuState.h"

enum MusicList{
	invalid_music = -1,
	SONG_1,
	SONG_2,
	SONG_3,
	SONG_4,
	SONG_5,
	SONG_6,
	songNum
};

const std::string MUSIC_LIST[songNum]{
	"Song 1",
	"Song 2",
	"Song 3",
	"Song 4",
	"Song 5",
	"Song 6"
};

class MusicSelectMenu: public MenuState{
private:
	int mode, level;

protected:
	//NONE

public:
	MusicSelectMenu(int vMode, int vLevel);

	virtual ~MusicSelectMenu(void);
	
	std::string name(void) const;

	/*MENU FUNCTIONS*/
	void Set_music(void);

};

#endif /* MUSICSELECTMENU_H */

