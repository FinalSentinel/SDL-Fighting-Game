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

#include "AudioMenu.h"
#include "ControlsMenu.h"
#include "VideoMenu.h"

OptionsMenu::OptionsMenu(){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Change Controls", new Texture(), std::bind(Change_controls, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Video Settings", new Texture(), std::bind(Video_settings, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Audio Settings", new Texture(), std::bind(Audio_settings, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(Back, this)));
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
    game->pushState(new ControlsMenu());

    return;
}

void OptionsMenu::Video_settings(){
    //TODO 
    std::cout<<"Video"<<std::endl;
    game->pushState(new VideoMenu());

    return;
}

void OptionsMenu::Audio_settings(){
    //TODO 
    std::cout<<"Audio"<<std::endl;
    game->pushState(new AudioMenu());

    return;
}

void OptionsMenu::Back(){
    game->popState();

    return;
}