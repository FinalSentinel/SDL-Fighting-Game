/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LevelSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on October 2, 2019, 1:41 AM
 */

#include "LevelSelectMenu.h"

#include "MusicSelectMenu.h"

LevelSelectMenu::LevelSelectMenu(int vMode): mode(vMode){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    for(int i = 0; i < levelNum; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        (LEVEL_LIST[i], new Texture(), std::bind(Set_level, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
    
}

LevelSelectMenu::~LevelSelectMenu(){
}



std::string LevelSelectMenu::name(){
    return "LevelSelectMenu";
}



/*MENU FUNCTIONS*/
void LevelSelectMenu::Set_level(){
    std::cout<<"set level: "<<LEVEL_LIST[selection]<<std::endl;
    
    game->pushState(new MusicSelectMenu(mode, selection));
    
    return;
}