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

StoryMenu::StoryMenu(){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("STORY STUFF", new Texture(), std::bind(Hold, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
}

StoryMenu::StoryMenu(const StoryMenu& orig){
}

StoryMenu::~StoryMenu(){
}

std::string StoryMenu::name(){
    return "StoryMenu";
}



/*MENU FUNCTIONS*/
void StoryMenu::Hold(){
    std::cout << "TEST HOLD TEST" << std::endl;

    return;
}