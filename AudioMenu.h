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
	static const char audioDefault[];
	
	
	
	AudioMenu();

	virtual ~AudioMenu();
	
	

	std::string name();
	
	void reload();
	
	
	
	void controllerButtonHandler();
	
	
	
	/*MENU FUNCTIONS*/
	void Master();
	void Music();
	void Voice();
	void Effects();
	void Default();
};

#endif /* AUDIOMENU_H */

