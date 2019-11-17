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
#include "TrainingMenu.h"
#include "VersusState.h"

const std::string VersusMenu::menuText[VersusMenu::numOptions] = {
	"Resume",
	"Combo List",
	"Demo",
	"Command List",
	"Training Options",
	"Options",
	"Hide Menu",
	"Return to Lobby",
	"Return To Main Menu"
};

void(VersusMenu::* const VersusMenu::menuActions[VersusMenu::numOptions])(void) = {
	&MenuState::back,
	&MenuState::TEMP,
	&MenuState::TEMP,
	&VersusMenu::Command_list,
	&VersusMenu::Training_options,
	&VersusMenu::Options,
	&VersusMenu::Hide_menu,
	&MenuState::TEMP,
	&VersusMenu::Return_to_menu
};



VersusMenu::VersusMenu(VersusState* versus): vstate(versus), hide(false){
	for(int i = 0; i < numOptions; i++){
		switch(vstate->get_mode()){
			case VERSUS:
			{
				if(!(i == COMBO_LIST || i == DEMO || i == TRAINING_OPTIONS || i == RETURN_TO_LOBBY)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			case ARCADE:
			{
				if(!(i == COMBO_LIST || i == DEMO || i == TRAINING_OPTIONS || i == RETURN_TO_LOBBY)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			case ONLINE:
			{
				if(!(i == COMBO_LIST || i == DEMO || i == TRAINING_OPTIONS)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			case TRAINING:
			{
				if(!(i == COMBO_LIST || i == DEMO || i == RETURN_TO_LOBBY)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			case COMBO:
			{
				if(!(i == TRAINING_OPTIONS || i == RETURN_TO_LOBBY)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			case TUTORIAL:
			{
				if(!(i == COMBO_LIST || i == TRAINING_OPTIONS || i == RETURN_TO_LOBBY)){
					options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
						(menuText[i], new Texture(), std::bind(menuActions[i], this)));
				}
			}
			break;

			default:
			{
				options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
					(menuText[i], new Texture(), std::bind(menuActions[i], this)));
			}
			break;
		}
	}
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

void VersusMenu::Training_options(void){
	game->pushState(new TrainingMenu(vstate));

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
