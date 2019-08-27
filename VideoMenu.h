/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 11:50 PM
 */

#ifndef VIDEOMENU_H
#define VIDEOMENU_H

#include "MenuState.h"



class VideoMenu: public MenuState{
private:

protected:

public:
	VideoMenu();

	VideoMenu(const VideoMenu& orig);

	virtual ~VideoMenu();
	
	

	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Back();
};

#endif /* VIDEOMENU_H */

