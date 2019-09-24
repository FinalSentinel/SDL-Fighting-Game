/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterSelectState.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 10:59 PM
 */

#include "CharacterSelectState.h"

#include "CharacterSelectMenu.h"
#include "VersusState.h"



CharacterSelectState::CharacterSelectState(int vMode): mode(vMode){
}

CharacterSelectState::~CharacterSelectState(){
}



void CharacterSelectState::load(){
    game->pushState(new CharacterSelectMenu(mode));

    return;
}

std::string CharacterSelectState::name(){
    return "CharacterSelectState";
}

void CharacterSelectState::resume(){
    game->popState();

    return;
}



/*MENU FUNCTIONS*/
