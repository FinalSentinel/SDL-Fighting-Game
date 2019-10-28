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
	//NONE

protected:
	//NONE

public:
	static const char audioDefault[];
	
	
	
	AudioMenu(void);

	virtual ~AudioMenu(void);
	
	std::string name(void) const;
	
	void reload(void);
	
	void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	void Master(void);
	void Music(void);
	void Voice(void);
	void Effects(void);
	void Default(void);

};

#endif /* AUDIOMENU_H */

