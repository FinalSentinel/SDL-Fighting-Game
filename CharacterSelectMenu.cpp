/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on September 23, 2019, 7:47 PM
 */

#include "CharacterSelectMenu.h"

#include "VersusState.h"

#include "Player.h"

CharacterSelectMenu::CharacterSelectMenu(int vMode): mode(vMode){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    for(int i = 0; i < 6 /*change to enum list num*/; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        ("Char " + std::to_string(i), new Texture(), std::bind(Set_character, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
    
}

CharacterSelectMenu::~CharacterSelectMenu(){
}



void CharacterSelectMenu::load(){
    selected[0] = false;
    //XXX
    selected[1] = true;
    
    MenuState::load();
}

std::string CharacterSelectMenu::name(){
    return "CharacterSelectMenu";
}

void CharacterSelectMenu::resume(){
    load();
    
    return;
}

void CharacterSelectMenu::update(){
    //TODO mode based loading for level/music?
    if(selected[0] == true && selected[1] == true){
        //TODO change to level select
        game->pushState(new LevelSelectMenu(mode));
    }
}



/*MENU FUNCTIONS*/
void CharacterSelectMenu::Set_character(){
    std::cout<<"set character: "<<selection<<std::endl;
    
    //TODO Set Player character choice
    //TODO player based logic
    game->getPlayersList()[0]->set_character(selection);
    selected[0] = true;
    
    return;
}