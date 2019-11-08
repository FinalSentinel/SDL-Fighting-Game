/* 
 * File:   GalleryMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:44 PM
 */

#include "GalleryMenu.h"

const std::string GalleryMenu::menuText[GalleryMenu::numOptions] = {
	"STORY STUFF"
	"Back"
};

void(GalleryMenu::* const GalleryMenu::menuActions[GalleryMenu::numOptions])(void) = {
	&MenuState::TEMP,
	&MenuState::back
};



GalleryMenu::GalleryMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

GalleryMenu::~GalleryMenu(void){
	//NONE
}

std::string GalleryMenu::name(void) const{
    return "GalleryMenu";
}

/*MENU FUNCTIONS*/
