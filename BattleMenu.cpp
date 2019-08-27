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

#include "VersusState.h"

BattleMenu::BattleMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("Versus");
    actions.emplace_back(std::bind(Versus, this));
    
    options.emplace_back("Online");
    actions.emplace_back(std::bind(Online, this));
    
    options.emplace_back("Training");
    actions.emplace_back(std::bind(Training, this));
    
    options.emplace_back("Combos");
    actions.emplace_back(std::bind(Combos, this));
    
    options.emplace_back("Tutorial");
    actions.emplace_back(std::bind(Tutorial, this));
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

BattleMenu::BattleMenu(const BattleMenu& orig){
}

BattleMenu::~BattleMenu(){
}



std::string BattleMenu::name(){
    return "BattleMenu";
}



/*MENU FUNCTIONS*/
void BattleMenu::Versus(){
    std::cout<<"Versus"<<std::endl;
    game->pushState(new VersusState(/*TODO Flags*/));

    return;
}

void BattleMenu::Online(){
    std::cout<<"Versus"<<std::endl;
    game->pushState(new VersusState(/*TODO Flags*/));

    return;
}

void BattleMenu::Training(){
    std::cout<<"Training"<<std::endl;
    game->pushState(new VersusState(/*TODO Flags*/));

    return;
}

void BattleMenu::Combos(){
    std::cout<<"Combos"<<std::endl;
    game->pushState(new VersusState(/*TODO Flags*/));

    return;
}

void BattleMenu::Tutorial(){
    std::cout<<"Tutorial"<<std::endl;
    game->pushState(new VersusState(/*TODO Flags*/));

    return;
}

void BattleMenu::Back(){
    std::cout<<"Main"<<std::endl;
    game->popState();

    return;
}