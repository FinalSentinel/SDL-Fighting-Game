/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 9:53 PM
 */

#include "CommandMenu.h"

CommandMenu::CommandMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
     */
    
    options.emplace_back("CHARACTER NAME");
    actions.emplace_back(std::bind(play, this));
    
    options.emplace_back("Move 1");
    actions.emplace_back(std::bind(play, this));
    
    options.emplace_back("Move 2");
    actions.emplace_back(std::bind(play, this));
    
    options.emplace_back("Move 3");
    actions.emplace_back(std::bind(play, this));
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(back, this));
}

CommandMenu::CommandMenu(const CommandMenu& orig){
}

CommandMenu::~CommandMenu(){
}

std::string CommandMenu::name(){
    return "CommandMenu";
}



/*MENU FUNCTIONS*/
void CommandMenu::play(){
    //TODO
    return;
}

void CommandMenu::back(){
    game->popState();
    
    return;
}
