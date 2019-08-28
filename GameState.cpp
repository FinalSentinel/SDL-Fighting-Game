/*
 * GameState.cpp
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#include "GameState.h"

#include "Player.h"

//template<typename State>
//State GameState<State>::state;

//FIXME something about this seems wrong
GameEngine* GameState::game;



bool GameState::get_seen(){
    return seen;
}

void GameState::eventHandler(SDL_Event e){
    //Check event type and pass to event specific handler
    switch(e.type){
        case SDL_CONTROLLERAXISMOTION:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(e.caxis.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(e.caxis.axis));

            if(e.caxis.value == 32767){
                std::locale loc;

                for(unsigned int i = 0; i < hold.length(); i++){
                    hold[i] = std::toupper(hold[i], loc);
                }
            }
            std::cout << "Player " << n << " " << hold << ": " << e.caxis.value << std::endl;

            controllerAxisHandler(e);
        }
            break;

        case SDL_CONTROLLERBUTTONDOWN:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(e.cbutton.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForButton(SDL_GameControllerButton((int)(e.cbutton.button)));
            for(unsigned int i = 0; i < hold.length(); i++){
                hold[i] = std::toupper(hold[i]);
            }
            std::cout << "Player " << n << " " << hold << std::endl;

            controllerButtonHandler(e);
        }
            break;

        case SDL_CONTROLLERBUTTONUP:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(e.cbutton.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForButton(SDL_GameControllerButton((int) (e.cbutton.button)));
            for(unsigned int i = 0; i < hold.length(); i++){
                hold[i] = std::tolower(hold[i]);
            }
            std::cout << "Player " << n << " " << hold << std::endl;

            controllerButtonHandler(e);
        }
            break;

        case SDL_KEYDOWN:
        {
            //XXX
            if(!e.key.repeat){
                std::string hold = SDL_GetKeyName(e.key.keysym.sym);
                for(unsigned int i = 0; i < hold.size(); i++){
                    hold[i] = std::toupper(hold[i]);
                }
                std::cout << hold << std::endl;
            }

            keyHandler(e);
        }
            break;

        case SDL_KEYUP:
        {
            //XXX
            if(!e.key.repeat){
                std::string hold = SDL_GetKeyName(e.key.keysym.sym);
                for(unsigned int i = 0; i < hold.size(); i++){
                    hold[i] = std::tolower(hold[i]);
                }
                std::cout << hold << std::endl;
            }

            keyHandler(e);
        }
            break;

        case SDL_WINDOWEVENT:
            windowHandler(e);
            break;

        default:
            //std::cerr<<"ERROR unknown event: "<<e.type<<std::endl;
            break;
    }

    return;
}

void GameState::set_seen(bool b){
    seen = b;
    
    return;
}