/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "AudioMenu.h"

AudioMenu::AudioMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

AudioMenu::AudioMenu(const AudioMenu& orig){
}

AudioMenu::~AudioMenu(){
}



std::string AudioMenu::name(){
    return "AudioMenu";
}



/*MENU FUNCTIONS*/
void AudioMenu::Back(){
    std::cout<<"Options"<<std::endl;
    game->popState();

    return;
}