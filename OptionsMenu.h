/* 
 * File:   OptionsMenu.h
 * Author: Clayton
 *
 * Created on August 25, 2019, 11:45 PM
 */

#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include "MenuState.h"



class OptionsMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(OptionsMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Options_Options{
		CHANGE_CONTROLS,
		VIDEO_SETTINGS,
		AUDIO_SETTINGS,
		BACK,
		numOptions
	};

	OptionsMenu(void);

	virtual ~OptionsMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Change_controls(void);
	void Video_settings(void);
	void Audio_settings(void);
	//   Back = MenuState::back(void);

};

#endif /* OPTIONSMENU_H */

