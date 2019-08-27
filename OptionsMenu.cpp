/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OptionsMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:45 PM
 */

#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("Change Controls");
    actions.emplace_back(std::bind(Change_controls, this));

    options.emplace_back("Video Settings");
    actions.emplace_back(std::bind(Video_settings, this));

    options.emplace_back("Audio Settings");
    actions.emplace_back(std::bind(Audio_settings, this));
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

OptionsMenu::OptionsMenu(const OptionsMenu& orig){
}

OptionsMenu::~OptionsMenu(){
}



std::string OptionsMenu::name(){
    return "OptionsMenu";
}



/*MENU FUNCTIONS*/
void OptionsMenu::Change_controls(){
    //TODO
    std::cout<<"Controls"<<std::endl;

    return;
}

void OptionsMenu::Video_settings(){
    //TODO 
    std::cout<<"Video"<<std::endl;

    return;
}

void OptionsMenu::Audio_settings(){
    //TODO 
    std::cout<<"Audio"<<std::endl;

    return;
}

void OptionsMenu::Back(){
    game->popState();

    return;
}