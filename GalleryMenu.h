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
	//NONE

protected:
	//NONE

public:
	GalleryMenu(void);

	GalleryMenu(const GalleryMenu& orig);

	virtual ~GalleryMenu(void);
	
	std::string name(void) const;
	
	/*MENU FUNCTIONS*/
	void Hold(void) const;
	//   Back = MenuState::back(void);

};

#endif /* GALLERYMENU_H */

