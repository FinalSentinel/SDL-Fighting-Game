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
	static const std::string menuText[];

	//TODO lambdas?
	static void(GalleryMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Gallery_Options{
		GALLERY_STUFF,
		BACK,
		numOptions
	};

	GalleryMenu(void);

	virtual ~GalleryMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	//   Back = MenuState::back(void);

};

#endif /* GALLERYMENU_H */

