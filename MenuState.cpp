/*
 * MenuState.cpp
 *
 *  Created on: Aug 20, 2019
 *      Author: Clayton
 */

#include "MenuState.h"

/*
MenuState MenuState::state;

MenuState* MenuState::instance(){
    return &state;
}
 */



MenuState::MenuState(){
}

MenuState::~MenuState(){
}

//TODO safe function calling on invalid indexes?
void MenuState::callAction(){
    actions[selection]();
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
    std::cout << "MENU STATE: ";

    for(int i = 0; i < options.size(); i++){
        buttons.emplace_back(new Texture());
        buttons[i]->loadText(game->gameWindow.renderer, options[i], 100);
    }
    if(!buttons.empty()){
        buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
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
    int x = game->gameWindow.get_w() / 5;
    //Menu height is the number of window height divided by numOptions + 2,
    //therefore equal blank space above and below.  Will implement scrolling.
    int h = game->gameWindow.get_h() / (std::min((int)buttons.size(), MAX_MENU_SIZE) + 2);

    for(int i = 0; i < MAX_MENU_SIZE && i < buttons.size(); i++){
        buttons[i + selection - index]->render(game->gameWindow.renderer, x, h * (i + 1), 3 * x, h);
    }

    return;
}

void MenuState::resume(){
    //TODO stuff
    GameState::set_seen(true);
    
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

void MenuState::controllerAxisHandler(SDL_Event e){
    if(e.caxis.value > 30000){
        switch(e.caxis.axis){
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

void MenuState::controllerButtonHandler(SDL_Event e){
    //TODO multiple control method exclusion
    //TODO player differentiation
    //TODO menu mapping
    //TODO make options files

    if(e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
        //TODO Player based menu control
        switch(e.cbutton.button){
            case SDL_CONTROLLER_BUTTON_A:
            {
                //Activate menu selection.
                callAction();
            }
                break;

            case SDL_CONTROLLER_BUTTON_B:
            {
                game->popState();
            }
                break;

            case SDL_CONTROLLER_BUTTON_X:
                break;

            case SDL_CONTROLLER_BUTTON_Y:
                break;

            case SDL_CONTROLLER_BUTTON_BACK:
                break;

            case SDL_CONTROLLER_BUTTON_GUIDE:
                break;

            case SDL_CONTROLLER_BUTTON_START:
            {
                close();
            }
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
                break;

            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
                break;

            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_UP:
            {
                if(index > 0){
                    index--;
                }
                else if(selection == 0){
                    index = std::min((int)buttons.size() - 1, MAX_MENU_SIZE - 1);
                }
                
                buttons[selection]->setRGBA();
                selection = (buttons.size() + selection - 1) % buttons.size();
                buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
                
                
            }
                break;

            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            {
                if(index < MAX_MENU_SIZE - 1 && index < buttons.size() - 1){
                    index++;
                }
                else if(selection == buttons.size() - 1){
                    index = 0;
                }
                
                buttons[selection]->setRGBA();
                selection = (buttons.size() + selection + 1) % buttons.size();
                buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
                
                
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

void MenuState::keyHandler(SDL_Event e){
}

void MenuState::windowHandler(SDL_Event e){
}
