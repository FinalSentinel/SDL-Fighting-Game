/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.h
 * Author: Clayton
 *
 * Created on August 23, 2019, 3:45 PM
 */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "MenuState.h"

enum Main_Options{
	BATTLE,
	STORY,
	GALLERY,
	OPTIONS,
	RETURN_TO_TITLE
};

class Song;

class MainMenu: public MenuState{
private:
	static const char mainMenuMusic[];
	
	Song* mainMenuSong;

protected:

public:
	MainMenu();

	virtual ~MainMenu();

	//static MainMenu* instance();


	
	void load();
	
	std::string name();
	
	void render();
	
	void unload();
	
	
	virtual void controllerButtonHandler();
	

	
	/*MENU FUNCTIONS*/
	void Battle();
	void Story();
	void Gallery();
	void Options();
	//   Return_to_title = MenuState::back()
};

#endif /* MAINMENU_H */

