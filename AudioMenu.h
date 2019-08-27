/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

protected:

public:
	AudioMenu();

	AudioMenu(const AudioMenu& orig);

	virtual ~AudioMenu();
	
	

	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Back();
};

#endif /* AUDIOMENU_H */

