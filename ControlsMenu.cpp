/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ControlsMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "ControlsMenu.h"

ControlsMenu::ControlsMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

ControlsMenu::ControlsMenu(const ControlsMenu& orig){
}

ControlsMenu::~ControlsMenu(){
}



std::string ControlsMenu::name(){
    return "ControlsMenu";
}



/*MENU FUNCTIONS*/
void ControlsMenu::Back(){
    std::cout<<"Options"<<std::endl;
    game->popState();

    return;
}