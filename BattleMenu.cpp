/* 
 * File:   BattleMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 10:59 PM
 */

#include "BattleMenu.h"

#include "CharacterSelectState.h"

BattleMenu::BattleMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Versus", new Texture(), std::bind(&BattleMenu::Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Online", new Texture(), std::bind(&BattleMenu::Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Training", new Texture(), std::bind(&BattleMenu::Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Combos", new Texture(), std::bind(&BattleMenu::Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Tutorial", new Texture(), std::bind(&BattleMenu::Char_select, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
}

BattleMenu::~BattleMenu(void){
	//NONE
}

std::string BattleMenu::name(void) const{
    return "BattleMenu";
}

/*MENU FUNCTIONS*/
void BattleMenu::Char_select(void){
    game->pushState(new CharacterSelectState(selection));
    std::cout<<game->get_back()->name()<<std::endl;

    return;
}
