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

void GameState::eventHandler(){
    //Check event type and pass to event specific handler
    switch(game->e.type){
        case SDL_CONTROLLERAXISMOTION:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(game->e.caxis.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(game->e.caxis.axis));

            if(game->e.caxis.value == 32767){
                std::locale loc;

                for(unsigned int i = 0; i < hold.length(); i++){
                    hold[i] = std::toupper(hold[i], loc);
                }
            }
            std::cout << "Player " << n << " " << hold << ": " << game->e.caxis.value << std::endl;

            controllerAxisHandler();
        }
            break;

        case SDL_CONTROLLERBUTTONDOWN:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(game->e.cbutton.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForButton(SDL_GameControllerButton((int)(game->e.cbutton.button)));
            for(unsigned int i = 0; i < hold.length(); i++){
                hold[i] = std::toupper(hold[i]);
            }
            std::cout << "Player " << n << " " << hold << std::endl;

            controllerButtonHandler();
        }
            break;

        case SDL_CONTROLLERBUTTONUP:
        {
            //XXX
            int n = -1;
            for(unsigned int i = 0; i < game->getPlayersList().size(); i++){
                if(game->getPlayersList()[i] != nullptr){
                    if(SDL_GameControllerFromInstanceID(game->e.cbutton.which) == game->getPlayersList()[i]->controller){
                        n = i + 1;
                    }
                }
            }
            std::string hold = SDL_GameControllerGetStringForButton(SDL_GameControllerButton((int) (game->e.cbutton.button)));
            for(unsigned int i = 0; i < hold.length(); i++){
                hold[i] = std::tolower(hold[i]);
            }
            std::cout << "Player " << n << " " << hold << std::endl;

            controllerButtonHandler();
        }
            break;

        case SDL_KEYDOWN:
        {
            //XXX
            if(!game->e.key.repeat){
                std::string hold = SDL_GetKeyName(game->e.key.keysym.sym);
                for(unsigned int i = 0; i < hold.size(); i++){
                    hold[i] = std::toupper(hold[i]);
                }
                std::cout << hold << std::endl;
            }

            keyHandler();
        }
            break;

        case SDL_KEYUP:
        {
            //XXX
            if(!game->e.key.repeat){
                std::string hold = SDL_GetKeyName(game->e.key.keysym.sym);
                for(unsigned int i = 0; i < hold.size(); i++){
                    hold[i] = std::tolower(hold[i]);
                }
                std::cout << hold << std::endl;
            }

            keyHandler();
        }
            break;

        case SDL_WINDOWEVENT:
            windowHandler();
            break;

        default:
            //std::cerr<<"ERROR unknown event: "<<game->e.type<<std::endl;
            break;
    }

    return;
}

void GameState::set_seen(bool b){
    seen = b;
    
    return;
}