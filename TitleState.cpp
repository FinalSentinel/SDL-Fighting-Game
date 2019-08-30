/*
 * TitleState.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include "TitleState.h"

#include "MainMenu.h"

#include "SDL.h"

/*
TitleState TitleState::state;

TitleState* TitleState::instance(){
    return &state;
}
 */

void TitleState::load(){
    //XXX
    std::cout << "TITLE STATE" << std::endl;

    //Load title texture
    titleTexture.loadImage(game->gameWindow.renderer, "Title hold.png");

    //Load title text
    titleText.loadText(game->gameWindow.renderer, "TITLE TEXT", 200);

    return;
}

std::string TitleState::name(){
    return "TitleState";
}

void TitleState::pause(){
    //TODO
    GameState::set_seen(false);
    
    return;
}

void TitleState::render(){
    //TODO recer clear?  clear color?
    SDL_RenderClear(game->gameWindow.renderer);

    //TODO fit image to window
    titleTexture.render(game->gameWindow.renderer, 0, 0, game->gameWindow.get_w(),
                                                         game->gameWindow.get_h());

    titleText.render(game->gameWindow.renderer, (game->gameWindow.get_w() - titleText.get_w()) / 2,
                                                (game->gameWindow.get_h() - titleText.get_h()) / 2);

    return;
}

void TitleState::resume(){
    //TODO
    GameState::set_seen(true);
    
    return;
}

void TitleState::unload(){
    //TODO
    titleTexture.~Texture();
    return;
}

void TitleState::update(){
    //TODO
    return;
}

void TitleState::controllerAxisHandler(){
    //TODO title gfx/sfx
    switch(game->e.caxis.axis){
        case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
        {
            if(game->e.caxis.value == 32767){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
        {
            if(game->e.caxis.value == 32767){
                game->pushState(new MainMenu());
            }
        }
            break;

        default:
            break;
    }
}

void TitleState::controllerButtonHandler(){
    //TODO multiple control method exclusion
    //TODO player differentiation

    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_A:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_B:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                //game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_X:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_Y:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_BACK:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                //Select button exits from title screen
                game->close();
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_START:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_LEFTSTICK:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;

        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
        {
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new MainMenu());
            }
        }
            break;
            ;

        default:
            break;
    }

    return;
}

void TitleState::keyHandler(){
    //TODO keys to switch state
    return;
}

void TitleState::windowHandler(){
    //TODO
    return;
}

