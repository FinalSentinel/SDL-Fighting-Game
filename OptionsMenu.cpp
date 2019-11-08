/* 
 * File:   OptionsMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:45 PM
 */

#include "OptionsMenu.h"

#include "AudioMenu.h"
#include "ControlsMenu.h"
#include "VideoMenu.h"

const std::string OptionsMenu::menuText[OptionsMenu::numOptions] = {
	"Change Controls",
	"Video Settings",
	"Audio Settings",
	"Back"
};

void(OptionsMenu::* const OptionsMenu::menuActions[OptionsMenu::numOptions])(void) = {
	&OptionsMenu::Change_controls,
	&OptionsMenu::Video_settings,
	&OptionsMenu::Audio_settings,
	&MenuState::back
};



OptionsMenu::OptionsMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

OptionsMenu::~OptionsMenu(void){
	//NONE
}

std::string OptionsMenu::name(void) const{
    return "OptionsMenu";
}

/*MENU FUNCTIONS*/
void OptionsMenu::Change_controls(void){
    //TODO
    std::cout<<"Controls"<<std::endl;
    game->pushState(new ControlsMenu());

    return;
}

void OptionsMenu::Video_settings(void){
    //TODO 
    std::cout<<"Video"<<std::endl;
    game->pushState(new VideoMenu());

    return;
}

void OptionsMenu::Audio_settings(void){
    //TODO 
    std::cout<<"Audio"<<std::endl;
    game->pushState(new AudioMenu());

    return;
}
