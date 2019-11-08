/* 
 * File:   MainMenu.h
 * Author: Clayton
 *
 * Created on August 23, 2019, 3:45 PM
 */

#ifndef MAINMENU_H
#define MAINMENU_H

#include "MenuState.h"



class Song;

class MainMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(MainMenu::* const menuActions[])(void);

	static const char mainMenuMusic[];
	
	Song* mainMenuSong;

protected:
	//NONE

public:
	enum Main_Options{
		BATTLE,
		STORY,
		GALLERY,
		OPTIONS,
		RETURN_TO_TITLE,
		numOptions
	};

	MainMenu(void);

	virtual ~MainMenu(void);
	
	void load(void);
	
	std::string name(void) const;
	
	void render(void) const;
	
	void resume(void);
	
	void unload(void);

	virtual void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	void Battle(void);
	void Story(void);
	void Gallery(void);
	void Options(void);
	//   Return_to_title = MenuState::back(void){

};

#endif /* MAINMENU_H */

