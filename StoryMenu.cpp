/* 
 * File:   StoryMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:44 PM
 */

#include "StoryMenu.h"

const std::string StoryMenu::menuText[StoryMenu::numOptions] = {
	"STORY STUFF",
	"Back"
};

void(StoryMenu::* const StoryMenu::menuActions[StoryMenu::numOptions])(void) = {
	&MenuState::TEMP,
	&MenuState::back
};



StoryMenu::StoryMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

StoryMenu::~StoryMenu(void){
	//NONE
}

std::string StoryMenu::name(void) const{
    return "StoryMenu";
}

/*MENU FUNCTIONS*/
