/* 
 * File:   CommandMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 9:53 PM
 */

#include "CommandMenu.h"

CommandMenu::CommandMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("CHARACTER NAME", new Texture(), std::bind(&CommandMenu::none, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 1", new Texture(), std::bind(&CommandMenu::Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 2", new Texture(), std::bind(&CommandMenu::Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Move 3", new Texture(), std::bind(&CommandMenu::Play, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
}

CommandMenu::~CommandMenu(void){
}

std::string CommandMenu::name(void) const{
    return "CommandMenu";
}

/*MENU FUNCTIONS*/
void CommandMenu::Play(void){
    //TODO
    return;
}

void CommandMenu::none(void) const{
    return;
}
