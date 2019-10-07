/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

public:
	MusicSelectMenu(int vMode, int vLevel);

	MusicSelectMenu(const MusicSelectMenu& orig);

	virtual ~MusicSelectMenu();
	
	
	
	std::string name();



	/*MENU FUNCTIONS*/
	void Set_music();
};

#endif /* MUSICSELECTMENU_H */

