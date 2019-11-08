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

const std::string ControlsMenu::menuText[ControlsMenu::numOptions] = {
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

void(ControlsMenu::* const ControlsMenu::menuActions[ControlsMenu::numOptions])(void) = {
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
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
	for(int i = UP; i <= PAUSE; i++){
		std::get<TEXT>(options[i]).append(": " + game->getPlayersList()[0]->controls[i]);
	}
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

void ControlsMenu::reload(void){
	for(int i = UP; i <= PAUSE; i++){
		std::get<TEXT>(options[i]) = menuText[i] + ": " + game->getPlayersList()[0]->controls[i - UP];
	}
    //TODO keyboard stuff

    for(int i = UP; i <= PAUSE; i++){
        std::get<GRAPHIC>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
    }

    if(!options.empty()){
        std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
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

void ControlsMenu::setButton(Player* p, const int n, const std::string button){
    if(n < versusControlsNum){
        for(int i = 0; i < versusControlsNum; i++){
            if(i == n){
                i++;
            }
            if(button == p->controls[i] && button != "-"){
                p->controls[i] = p->controls[n];
            }
        }

        p->controls[n] = button;
    }
    else{
        std::cerr << "ERROR setButton position out of bounds" << std::endl;
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
    if(selection >= 1 && selection < versusControlsNum && game->e.caxis.value > 30000){
        if(selection >= PUNCH + 1 && selection <= versusControlsNum){
            std::cout << "Set Button" << std::endl;

            setButton(game->getPlayersList()[0], selection - 1, SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(game->e.caxis.axis)));
            game->getPlayersList()[0]->saveControls();

            reload();
        }
    }
    
    else if(config[0]){
        if(game->e.caxis.value > 30000){
            if(game->e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT || game->e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT){
                setButton(game->getPlayersList()[0], configNum[0], SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(game->e.caxis.axis)));

                configNum[0]++;
                
                if(configNum[0] >= TAUNT && configNum[0] < RECORD){
                    configNum[0] = RECORD;
                }
                else if(configNum[0] >= PAUSE){
                    config[0] = false;

                    game->fileI.close();

                    game->getPlayersList()[0]->saveControls();

                    reload();

                    for(unsigned int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }

                prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0]], 100);
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
    if(selection >= 1 && selection <= versusControlsNum && game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN &&
            game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_UP && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_DOWN){
        switch(game->e.cbutton.button){
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
                returnToTop();

                break;
            }
            
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
                if(selection >= PUNCH + 1 && selection < versusControlsNum){
                    std::cout << "Set Button" << std::endl;
                    
                    setButton(game->getPlayersList()[0], selection - 1, "-");
                    game->getPlayersList()[0]->saveControls();
                    
                    reload();
                }
                break;
            }

            default:{
                if(selection >= PUNCH + 1 && selection < versusControlsNum){
                    std::cout << "Set Button" << std::endl;
                    
                    setButton(game->getPlayersList()[0], selection - 1, SDL_GameControllerGetStringForButton(SDL_GameControllerButton(game->e.cbutton.button)));
                    game->getPlayersList()[0]->saveControls();
                    
                    reload();
                }
                break;
            }
        }
    }
    else if(config[0]){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN &&
                game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_UP && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_DOWN &&
                game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_LEFT && game->e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_RIGHT){
            if(game->e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
                setButton(game->getPlayersList()[0], configNum[0], SDL_GameControllerGetStringForButton(SDL_GameControllerButton(game->e.cbutton.button)));
                
                configNum[0]++;
                
                if(configNum[0] >= TAUNT && configNum[0] < RECORD){
                    configNum[0] = RECORD;
                }
                else if(configNum[0] >= PAUSE){
                    config[0] = false;

                    game->fileI.close();

                    game->getPlayersList()[0]->saveControls();

                    reload();

                    for(unsigned int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }
                
                prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0]], 100);
            }
            else{
                config[0] = false;

                game->fileI.close();

                for(unsigned int i = 0; i < options.size(); i++){
                    //TODO get RGBA
                    std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                }
                std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
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
	configNum[0] = PUNCH;

	for(unsigned int i = 0; i < options.size(); i++){
		//TODO get RGBA
		std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
	}

	prompt[0].loadText(game->gameWindow.renderer, menuText[configNum[0]], 100);

    return;
}

void ControlsMenu::Default(void){
    std::cout << "Default" << std::endl;

    game->fileI.open(controlDefault);

    if(!game->fileI.is_open()){
        std::cerr << "ERROR cannot open controls default." << std::endl;
        
        game->getPlayersList()[0]->saveControls();
    }
    else{
		char hold[32];

        for(int i = 0; i < versusControlsNum; i++){
            game->fileI.getline(hold, 32);
            
            game->getPlayersList()[0]->controls[i] = std::string(hold);
        }
        
        game->getPlayersList()[0]->saveControls();
        
        game->fileI.close();
    
        reload();
    }

    return;
}

void ControlsMenu::none(void){
    return;
}
