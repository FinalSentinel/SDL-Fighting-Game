/*
 * Player.cpp
 *
 *  Created on: Aug 16, 2019
 *      Author: Clayton
 */

#include <fstream>
#include <iostream>
#include <sstream>

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
    std::ifstream ifs;
    ifs.open(controlConfig);
    if(!ifs.is_open()){
        std::cerr<<"ERROR unable to open control config file (READING)"<<std::endl;
        ifs.close();
    }
    else{
        std::stringstream hold;
        std::size_t pos = 0;
        
        hold << ifs.rdbuf();
        //FIXME function clears file
        
        ifs.close();
        
        for(int i = 1; i < playerNum; i++){
            pos = hold.str().find("!", pos) + 1;
        }
        
        if(pos == hold.str().npos){
            std::cerr<<"ERROR cannot find Player control config"<<std::endl;
        }
        else{
            std::ofstream ofs;
            
            ofs.open(controlConfig);
            if(!ofs.is_open()){
                std::cerr<<"ERROR unable to open control config file (WRITING)"<<std::endl;
            }
            else{
                std::string temp = hold.str();
                
                temp.erase(pos, hold.str().find("!", pos) - pos);
                for(int i = 0; i < versusControlsNum; i++){
                    temp.insert(pos, controls[versusControlsNum - (i + 1)] + '\n');
                }
                
                ofs << temp;
            }
            ofs.close();
        }
    }
    
    return;
}