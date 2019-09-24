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

CharacterSelectMenu::CharacterSelectMenu(int vMode): mode(vMode){
    selected[0] = 0;
    //XXX
    selected[1] = 3;
    
    stageSetting[LEVEL] = -1;
    //XXX
    stageSetting[MUSIC] = -1;
    
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



std::string CharacterSelectMenu::name(){
    return "CharacterSelectMenu";
}

void render(){
    //TODO level/music render stuff
    
    return;
}

void CharacterSelectMenu::update(){
    if(selected[0] == 1 || selected[1] == 1){
        level = true;
    }
    if(selected[0] == 2 || selected[1] == 2){
        music = true;
    }
    if(selected[0] == 3 && selected[1] == 3){
        //TODO pass level and music
        game->pushState(new VersusState(mode));
    }
}



/*MENU FUNCTIONS*/
void CharacterSelectMenu::Set_character(){
    //TODO Set Player character choice
    
    //TODO player based logic
    selected[0]++;
    
    return;
}