/* 
 * File:   AudioMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 11:50 PM
 */

#ifndef AUDIOMENU_H
#define AUDIOMENU_H

#include "MenuState.h"



class AudioMenu: public MenuState{
private:
	static const char audioDefault[];

	static const std::string menuText[];

	//TODO lambdas?
	static void(AudioMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Audio_Options{
		MASTER,
		MUSIC,
		VOICES,
		EFFECTS,
		DEFAULT,
		BACK,
		numOptions
	};
	
	AudioMenu(void);

	virtual ~AudioMenu(void);
	
	std::string name(void) const;
	
	void reload(void);
	
	void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	void Master(void);
	void Music(void);
	void Voices(void);
	void Effects(void);
	void Default(void);

};

#endif /* AUDIOMENU_H */

