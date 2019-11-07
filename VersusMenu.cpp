/*
 * VersusMenu.cpp
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#include "VersusMenu.h"

#include "CommandMenu.h"
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "VersusState.h"

//VersusMenu VersusMenu::menu;
//
//VersusMenu* VersusMenu::instance(void){
//    return &menu;
//}

VersusMenu::VersusMenu(const int vMode): mode(vMode), hide(false){

    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&TEMP, this)));
    
    */

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Resume", new Texture(), std::bind(&MenuState::back, this)));

    if(mode == COMBO){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        ("Combo List", new Texture(), std::bind(&MenuState::TEMP, this)));
    }

    if(mode == COMBO){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        ("Demo", new Texture(), std::bind(&MenuState::TEMP, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Command List", new Texture(), std::bind(&VersusMenu::Command_list, this)));

    if(mode == TRAINING){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        ("Training Options", new Texture(), std::bind(&MenuState::TEMP, this)));
    }

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Options", new Texture(), std::bind(&VersusMenu::Options, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Hide Menu", new Texture(), std::bind(&VersusMenu::Hide_menu, this)));
    
    if(mode == ONLINE){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        ("Return to Lobby", new Texture(), std::bind(&MenuState::TEMP, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Return To Main Menu", new Texture(), std::bind(&VersusMenu::Return_to_menu, this)));
    
    //TODO Where to put display options?
    //TODO Character Select
}

VersusMenu::~VersusMenu(void){
    //NONE
};

void VersusMenu::load(void){
    MenuState::load();

    std::cout << "VERSUS MENU" << std::endl;

    return;
}

std::string VersusMenu::name(void) const{
    return "VersusMenu";
}

void VersusMenu::render(void) const{
    if(!hide){
        MenuState::render();
    }

    return;
}

void VersusMenu::controllerButtonHandler(void){
    //TODO multiple control method exclusion
    //TODO player differentiation
    //TODO menu mapping
    //TODO make options files
    bool hold = hide;
    
    if(!hide){
        MenuState::controllerButtonHandler();
    }
    
    if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN && hide == hold){

        //TODO Player based menu control
        switch(game->e.cbutton.button){
            case SDL_CONTROLLER_BUTTON_A:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_B:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_X:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_Y:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_BACK:
            {
            }
                break;

            case SDL_CONTROLLER_BUTTON_GUIDE:
                break;

            case SDL_CONTROLLER_BUTTON_START:
            {
            }
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
            {
                hide = false;
            }
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_UP:
            {
            }
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            {
            }
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            {
                //TODO stuff
            }
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            {
                //TODO stuff
            }
                break;

            case SDL_CONTROLLER_BUTTON_MAX:
                break;

            default:
                break;
        }
    }

    return;
}

/*MENU FUNCTIONS*/
void VersusMenu::Return_to_menu(void){
    game->changeState(new MainMenu());

    return;
}

void VersusMenu::Command_list(void){
    game->pushState(new CommandMenu());

    return;
}

void VersusMenu::Options(void){
    game->pushState(new OptionsMenu());
    
    return;
}

void VersusMenu::Hide_menu(void){
    hide = true;

    return;
}
