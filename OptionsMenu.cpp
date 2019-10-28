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

OptionsMenu::OptionsMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Change Controls", new Texture(), std::bind(&OptionsMenu::Change_controls, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Video Settings", new Texture(), std::bind(&OptionsMenu::Video_settings, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Audio Settings", new Texture(), std::bind(&OptionsMenu::Audio_settings, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
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
