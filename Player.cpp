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
const char Player::controlDefault[] = "controlConfigDefault.txt";



Player::Player(const int num, SDL_GameController* co, Character* ch): 
				playerNum(num), controller(co), character(ch){
    std::ifstream conIF;
    std::string hold;

	conIF.open(controlDefault);
	if(!conIF.is_open()){
		std::cerr << "ERROR unable to open control default." << std::endl;
	}
	else{
		for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
			hold = "";
			if(std::getline(conIF, hold)){
				if(hold == ""){
					std::cerr << "ERROR control default file corruption." << std::endl;

					i = SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX;
				}
				else{
					if(hold == "-"){
						hold = "-1";
					}
					controls[i] = std::stoi(hold);
				}
			}
		}
		conIF.close();
	}
    
    conIF.open(controlConfig);
	if(!conIF.is_open()){
		std::cerr << "ERROR unable to open control config." << std::endl;
	}
	else{
		for(int i = 0; i < playerNum - 1; i++) while(std::getline(conIF, hold) && hold != "!");
		for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
			hold = "";
			if(std::getline(conIF, hold)){
				if(hold == "!" || hold == ""){
					std::cerr << "ERROR control config file corruption." << std::endl;

					i = SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX;
				}
				else{
					if(hold == "-"){
						hold = "-1";
					}
					controls[i] = std::stoi(hold);
				}
			}
		}
		conIF.close();
	}
    
    charID = ERROR_CHARACTER;
}
        
Player::~Player(void){
	if(controller != nullptr){
		SDL_GameControllerClose(controller);
		controller = nullptr;
	}
	if(character != nullptr){
		delete character;
		controller = nullptr;
	}
}

CharacterID Player::get_character(void) const{
    return charID;
}

//TODO move to controls menu
void Player::saveControls(void) const{
    std::ifstream ifs;
    ifs.open(controlConfig);
    if(!ifs.is_open()){
        std::cerr<<"ERROR unable to open control config file (READING)"<<std::endl;
    }
    else{
        std::stringstream hold;
        std::size_t pos = 0;
        
        hold << ifs.rdbuf();
        
        ifs.close();
        
        for(int i = 0; i < playerNum; i++){
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
                for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
					int tester = controls[SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX - (i + 1)];
					if(controls[SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX - (i + 1)] < 0){
						std::string test2 = "-\n";
						temp.insert(pos, "-\n");
					}
					else{
						std::string test2 = std::to_string(controls[SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX - (i + 1)]) + '\n';
						temp.insert(pos, std::to_string(controls[SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX - (i + 1)]) + '\n');
					}
                }
                
                ofs << temp;

				ofs.close();
            }
        }
    }
    
    return;
}

int Player::setButton(const int action, const int button){
	int n = -1;
	if(action < 0 || action >= num_versusActions){
		std::cerr << "ERROR invalid action." << std::endl;
	}
	else if(button < 0 || button >= SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX){
		std::cerr << "ERROR invalid button" << std::endl;
	}
	else if(controls[button] != action){
		for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
			if(i == button){
				i++;
			}
			if(controls[i] == action){
				n = controls[button];
				controls[i] = n;

				break;
			}
		}

		controls[button] = action;
	}

	return n;
}

void Player::set_character(const CharacterID ch){
    //TODO load character from number
    if(ch >= 0){
        charID = ch;
    }
    
    return;
}
