/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GalleryMenu.h
 * Author: Clayton
 *
 * Created on August 25, 2019, 11:44 PM
 */

#ifndef GALLERYMENU_H
#define GALLERYMENU_H

#include "MenuState.h"

class GalleryMenu: public MenuState{
private:

protected:

public:
	GalleryMenu();

	GalleryMenu(const GalleryMenu& orig);

	virtual ~GalleryMenu();
	
	
	
	std::string name();

	
	
	/*MENU FUNCTIONS*/
	void Hold();
	void Back();
};

#endif /* GALLERYMENU_H */

