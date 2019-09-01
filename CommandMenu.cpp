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
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("CHARACTER NAME", new Texture(), std::bind(none, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 1", new Texture(), std::bind(Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 2", new Texture(), std::bind(Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 3", new Texture(), std::bind(Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
}

CommandMenu::CommandMenu(const CommandMenu& orig){
}

CommandMenu::~CommandMenu(){
}

std::string CommandMenu::name(){
    return "CommandMenu";
}



/*MENU FUNCTIONS*/
void CommandMenu::Play(){
    //TODO
    return;
}

void CommandMenu::none(){
    return;
}