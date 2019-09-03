/*
 * Player.cpp
 *
 *  Created on: Aug 16, 2019
 *      Author: Clayton
 */

#include <fstream>

#include "Player.h"

#include "Character.h"



const char Player::controlConfig[] = "controlConfig.txt";



Player::Player(int num, SDL_GameController* co, Character* ch):
               playerNum(num), controller(co), character(ch)   {
    std::ifstream conIF;
    std::string hold = "";
    
    conIF.open(controlConfig);
    for(int i = 0; i < num - 1; i++) while(std::getline(conIF, controls[i]) && hold != "!");
    for(int i = 0; i < versusControlsNum; i++){
        std::getline(conIF, controls[i]);
    }
    conIF.close();
}
        
Player::~Player(){
    SDL_GameControllerClose(controller);
}



void Player::saveControls(){
    //TODO
    
    return;
}

void Player::setControls(std::string* c){
    for(int i = 0; i < versusControlsNum; i++){
        controls[i] = c[i];
    }
    
    return;
}