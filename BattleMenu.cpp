/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BattleMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 10:59 PM
 */

#include "BattleMenu.h"

#include "CharacterSelectState.h"

BattleMenu::BattleMenu(){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Versus", new Texture(), std::bind(Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Online", new Texture(), std::bind(Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Training", new Texture(), std::bind(Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Combos", new Texture(), std::bind(Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Tutorial", new Texture(), std::bind(Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
}

BattleMenu::~BattleMenu(){
}



std::string BattleMenu::name(){
    return "BattleMenu";
}



/*MENU FUNCTIONS*/
void BattleMenu::Char_select(){
    game->pushState(new CharacterSelectState(selection));
    std::cout<<game->get_back()->name()<<std::endl;

    return;
}