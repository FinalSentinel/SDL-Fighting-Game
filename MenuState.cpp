/*
 * MenuState.cpp
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#include "MenuState.h"

#include "Texture.h"
#include "SFX.h"



const char MenuState::menuClick[] = "grunt.ogg";
SFX* MenuState::menuClickSFX = nullptr;



MenuState::MenuState(){
    if(menuClickSFX == nullptr){
        menuClickSFX = game->gameAudio.loadEffect(menuClick);
        if(!menuClickSFX){
            std::cerr << "ERROR loading menu click file" << std::endl;
        }
    }
}

MenuState::~MenuState(){
    game->gameAudio.unloadEffect(menuClickSFX);
    if(menuClickSFX != nullptr){
        std::cerr<<"ERROR menu click not unloaded properly"<<std::endl;
    }
}

void MenuState::back(){
    game->popState();
    std::cout<<game->get_back()->name()<<std::endl;
    
    return;
}

//TODO safe function calling on invalid indexes?
void MenuState::callAction(){
    std::get<FUNCTION>(options[selection])();
    return;
}

void MenuState::close(){
    while(game->get_back()->name().substr(game->get_back()->name().length() - 4, 4) == "Menu" &&
          game->get_back()->name() != "MainMenu"){
        game->popState();
    }

    return;
}

void MenuState::load(){
    std::cout << "MENU STATE: " << name() << std::endl;

    for(int i = 0; i < options.size(); i++){
        std::get<GRAPHIC>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
    }
    if(!options.empty()){
        std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
    }
    
    return;
}

void MenuState::pause(){
    //TODO
    GameState::set_seen(false);
    
    return;
} 

void MenuState::render(){
    //Menu x position is always at 3/5 of window width.
    int x = game->gameWindow.getWidth() / 5;
    //Menu height is the window height divided by numOptions + 2,
    //therefore equal blank space above and below.  Will implement scrolling.
    int h = game->gameWindow.getHeight() / (std::min((int)options.size(), MAX_MENU_SIZE) + 2);

    for(int i = 0; i < MAX_MENU_SIZE && i < options.size(); i++){
        std::get<GRAPHIC>(options[i + selection - index])->render(game->gameWindow.renderer, x, h * (i + 1), 3 * x, h);
    }

    return;
}

void MenuState::resume(){
    //TODO stuff
    GameState::set_seen(true);
    
    return;
}

void MenuState::returnToTop(){
    std::get<GRAPHIC>(options[selection])->setRGBA();

    index = 0;
    selection = 0;
    
    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
    
    return;
}

void MenuState::unload(){
    //TODO unload stuff

    return;
}

void MenuState::update(){
    //TODO reverse updating menu options?

    //TODO if empty unload

    return;
}

void MenuState::controllerAxisHandler(){
    if(game->e.caxis.value > 30000){
        switch(game->e.caxis.axis){
            case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
                break;

            case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
                break;

            default:
                break;
        }
    }

    return;
}

void MenuState::controllerButtonHandler(){
    //TODO multiple control method exclusion
    //TODO player differentiation
    //TODO menu mapping
    //TODO make options files

    if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
        //TODO Player based menu control
        switch(game->e.cbutton.button){
            case SDL_CONTROLLER_BUTTON_A:
            {
                //Activate menu selection.
                callAction();
                
                break;
            }

            case SDL_CONTROLLER_BUTTON_B:
            {
                back();
                
                break;
            }

            case SDL_CONTROLLER_BUTTON_X:
                break;

            case SDL_CONTROLLER_BUTTON_Y:
                break;

            case SDL_CONTROLLER_BUTTON_BACK:
                break;

            case SDL_CONTROLLER_BUTTON_GUIDE:
                break;

            case SDL_CONTROLLER_BUTTON_START:{
                close();
                break;
            }

            case SDL_CONTROLLER_BUTTON_LEFTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_UP:{
                if(index > 0){
                    index--;
                }
                else if(selection == 0){
                    index = std::min((int) options.size() - 1, MAX_MENU_SIZE - 1);
                }

                std::get<GRAPHIC>(options[selection])->setRGBA();
                selection = (options.size() + selection - 1) % options.size();
                std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                
                game->gameAudio.play(menuClickSFX, SYSTEM_SFX);

                break;
            }

            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:{
                if(index < MAX_MENU_SIZE - 1 && index < options.size() - 1){
                    index++;
                }
                else if(selection == options.size() - 1){
                    index = 0;
                }

                std::get<GRAPHIC>(options[selection])->setRGBA();
                selection = (options.size() + selection + 1) % options.size();
                std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                
                game->gameAudio.play(menuClickSFX, SYSTEM_SFX);

                break;
            }

            case SDL_CONTROLLER_BUTTON_MAX:
                break;

            default:
                break;
        }
    }

    return;
}

void MenuState::keyHandler(){
    
    return;
}

void MenuState::windowHandler(){
    
    return;
}
