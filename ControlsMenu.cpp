/* 
 * File:   ControlsMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "ControlsMenu.h"

#include "Player.h"

#include <ios>

//TODO Keyboard controls
//TODO Menu controls

const char ControlsMenu::controlDefault[] = "controlConfigDefault.txt";

const std::string ControlsMenu::menuText[ControlsMenu::num_ControlsOptions] = {
	"Quick Config",
	"UP",
	"DOWN",
	"LEFT",
	"RIGHT",
	"PUNCH",
	"KICK",
	"HEAVY",
	"SPECIAL",
	"P+K",
	"P+S",
	"K+H",
	"P+K+H",
	"P+K+H+S",
	"TAUNT",
	"RECORD",
	"PLAY",
	"RESET",
	"PAUSE",
	"Default",
	"Back"
};

void(ControlsMenu::* const ControlsMenu::menuActions[ControlsMenu::num_ControlsOptions])(void) = {
	&ControlsMenu::Quick_config,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::none,
	&ControlsMenu::Default,
	&MenuState::back
};



ControlsMenu::ControlsMenu(void){
	for(int i = 0; i < num_ControlsOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
	reloadMenu();

    //TODO setup keyboard stuff

	for(int i = 0; i < MAX_PLAYERS; i++){
		config[i] = false;
	}
	for(int i = 0; i < MAX_PLAYERS; i++){
		configNum[i] = 0;
	}
}

ControlsMenu::~ControlsMenu(void){
	//NONE
}

std::string ControlsMenu::name(void) const{
    return "ControlsMenu";
}

void ControlsMenu::reloadMenu(void){
	for(int i = 0; i < Player::num_versusActions; i++){
		controlMap[i] = "-";
	}
	for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX; i++){
		if(game->getPlayersList()[0]->controls[i] >= 0 && game->getPlayersList()[0]->controls[i] < num_ControlsOptions){
			controlMap[game->getPlayersList()[0]->controls[i]] = SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(i));
		}
	}
	for(int i = SDL_CONTROLLER_AXIS_MAX; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
		if(game->getPlayersList()[0]->controls[i] >= 0 && game->getPlayersList()[0]->controls[i] < num_ControlsOptions){
			controlMap[game->getPlayersList()[0]->controls[i]] = SDL_GameControllerGetStringForButton(SDL_GameControllerButton(i - SDL_CONTROLLER_AXIS_MAX));
		}
	}

	int pos = 0;
	for(int i = 0; i < Player::num_versusActions; i++){
		pos = std::get<TEXT>(options[i + UP]).find(":");

		if(pos != std::string::npos){
			std::get<TEXT>(options[i + UP]).erase(pos);
		}

		std::get<TEXT>(options[i + UP]).append(": " + controlMap[i]);
	}
    //TODO keyboard stuff

    for(int i = UP; i <= PAUSE; i++){
        std::get<TEXTURE>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
    }

    if(!options.empty()){
        std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
    }

    return;
}

void ControlsMenu::render(void) const{
    MenuState::render();

    if(config[0]){
        //Menu x position is always at 3/5 of window width.
        int x = game->gameWindow.getWidth() / 5;
        int y = game->gameWindow.getHeight() / 3;

        prompt[0].render(game->gameWindow.renderer, x, y, x * 3, y);
    }

    return;
}

void ControlsMenu::update(void){
    //NONE

    return;
}

//TODO console output stuff
void ControlsMenu::controllerAxisHandler(void){
    //TODO player differentiation
    //TODO menu mapping
    if(selection >= UP && selection <= PAUSE && game->e.caxis.value > 30000){
		int pos = std::get<TEXT>(options[selection]).find(":") + 2;
        if(selection >= PUNCH && selection < PAUSE &&
				std::get<TEXT>(options[selection]).substr(pos) != SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(game->e.caxis.axis))){
            std::cout << "Set Button" << std::endl;

			std::string hold = std::get<TEXT>(options[selection]).substr(pos);

			int replace = game->getPlayersList()[0]->setButton(selection - UP, game->e.caxis.axis);
			game->getPlayersList()[0]->saveControls();

			std::get<TEXT>(options[selection]).erase(pos);
			std::get<TEXT>(options[selection]).append(SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(game->e.caxis.axis)));

			std::get<TEXTURE>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);
			std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);

			if(replace >= 0){
				pos = std::get<TEXT>(options[replace + UP]).find(":") + 2;

				std::get<TEXT>(options[replace + UP]).erase(pos);
				std::get<TEXT>(options[replace + UP]).append(hold);

				std::get<TEXTURE>(options[replace + UP])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[replace + UP]), 100);
			}
        }
    }
    else if(config[0]){
        if(game->e.caxis.value > 30000){
            if(game->e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT || game->e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT){
				game->getPlayersList()[0]->setButton(configNum[0], game->e.caxis.axis);

                configNum[0]++;
                
                if(configNum[0] >= Player::TAUNT && configNum[0] < Player::RECORD){
                    configNum[0] = Player::RECORD;
                }
                else if(configNum[0] >= Player::PAUSE){
                    config[0] = false;

                    game->getPlayersList()[0]->saveControls();

                    reloadMenu();

                    for(unsigned int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }

                prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0] + UP], 100);
            }
        }
    }
    else{
        MenuState::controllerAxisHandler();
    }

    return;
}

//TODO console output stuff
void ControlsMenu::controllerButtonHandler(void){
    //TODO player differentiation
    if(selection >= UP && selection <= PAUSE && game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN &&
            game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_UP && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_DOWN){
		int pos = std::get<TEXT>(options[selection]).find(":") + 2;
        switch(game->e.cbutton.button){
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			{
                returnToTop();
            }
			break;
            
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			{
                if(selection >= PUNCH && selection < PAUSE && std::get<TEXT>(options[selection]).substr(pos) != "-"){
                    std::cout << "Erase Button" << std::endl;
                    
					for(int i = 0; i < Player::num_versusActions; i++){
						if(game->getPlayersList()[0]->controls[i] == selection - UP){
							game->getPlayersList()[0]->setButton(-1, i);
							game->getPlayersList()[0]->saveControls();

							std::get<TEXT>(options[selection]).erase(pos);
							std::get<TEXT>(options[selection]).append("-");

							std::get<TEXTURE>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);

							i = Player::num_versusActions;
						}
					}
                }
            }
			break;

            default:
			{
                if(selection >= PUNCH && selection < PAUSE &&
						std::get<TEXT>(options[selection]).substr(pos) != SDL_GameControllerGetStringForButton(SDL_GameControllerButton(game->e.cbutton.button))){
                    std::cout << "Set Button" << std::endl;

					std::string hold = std::get<TEXT>(options[selection]).substr(pos);

					int replace = game->getPlayersList()[0]->setButton(selection - UP, SDL_CONTROLLER_AXIS_MAX + game->e.cbutton.button);
                    game->getPlayersList()[0]->saveControls();

					std::get<TEXT>(options[selection]).erase(pos);
					std::get<TEXT>(options[selection]).append(SDL_GameControllerGetStringForButton(SDL_GameControllerButton(game->e.cbutton.button)));

					std::get<TEXTURE>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);
					std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);

					if(replace >= 0){
						pos = std::get<TEXT>(options[replace + UP]).find(":") + 2;

						std::get<TEXT>(options[replace + UP]).erase(pos);
						std::get<TEXT>(options[replace + UP]).append(hold);

						std::get<TEXTURE>(options[replace + UP])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[replace + UP]), 100);
					}
                }
            }
			break;
        }
    }
    else if(config[0]){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN &&
                game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_UP && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_DOWN &&
                game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_LEFT && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_RIGHT){
            if(game->e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
				game->getPlayersList()[0]->setButton(configNum[0], SDL_CONTROLLER_AXIS_MAX + game->e.cbutton.button);
                
                configNum[0]++;
                
                if(configNum[0] >= Player::TAUNT && configNum[0] < Player::RECORD){
                    configNum[0] = Player::RECORD;
                }
                else if(configNum[0] >= Player::PAUSE){
                    config[0] = false;

                    game->getPlayersList()[0]->saveControls();

                    reloadMenu();

                    for(unsigned int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }
                
                prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0] + UP], 100);
            }
            else{
                config[0] = false;

                game->fileI.close();

				//TODO loadControls function.

                for(unsigned int i = 0; i < options.size(); i++){
                    //TODO get RGBA
                    std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                }
                std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
            }
        }
    }
    else{
        MenuState::controllerButtonHandler();
    }

    return;
}

/*MENU FUNCTIONS*/
void ControlsMenu::Quick_config(void){
    std::cout << "Quick Config" << std::endl;

	config[0] = true;
	configNum[0] = Player::PUNCH;

	for(unsigned int i = 0; i < options.size(); i++){
		//TODO get RGBA
		std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
	}

	prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0] + UP], 100);

    return;
}

void ControlsMenu::Default(void){
    std::cout << "Default" << std::endl;

    game->fileI.open(controlDefault);

    if(!game->fileI.is_open()){
        std::cerr << "ERROR cannot open controls default." << std::endl;
    }
    else{
		char hold[4];

        for(int i = 0; i < SDL_CONTROLLER_AXIS_MAX + SDL_CONTROLLER_BUTTON_MAX; i++){
            game->fileI.getline(hold, 4);
            
			if(hold[0] == '-'){
				hold[0] = '-';
				hold[1] = '1';
			}
			int test1 = std::atoi(hold);
			game->getPlayersList()[0]->controls[i] = std::atoi(hold);
        }
        
        game->getPlayersList()[0]->saveControls();
        
        game->fileI.close();
    
        reloadMenu();
    }

    return;
}

void ControlsMenu::none(void){
    return;
}
