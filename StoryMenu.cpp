/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StoryMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:44 PM
 */

#include "StoryMenu.h"

StoryMenu::StoryMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("STORY STUFF", new Texture(), std::bind(&StoryMenu::Hold, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
}

StoryMenu::~StoryMenu(void){
}

std::string StoryMenu::name(void) const{
    return "StoryMenu";
}

/*MENU FUNCTIONS*/
void StoryMenu::Hold(void){
    std::cout << "TEST HOLD TEST" << std::endl;

    return;
}
