/*
 * VersusState.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include "VersusState.h"

#include "VersusMenu.h"

#include "Box.h"
#include "Character.h"
#include "Player.h"


/*
VersusState VersusState::state;

VersusState* VersusState::instance(){
    return &state;
}
*/

//TODO Change to Character Frame based

void VersusState::decollide(Player* p1, Player* p2){
    //Decollides horizontally.
    //TODO camera based walls
    //TODO cleanup

    /*CHARACTER COLLISION*/
    int w = 0;
    for(unsigned int i = 0; i < p1->character->getColBoxes().size(); i++){
        for(unsigned int j = 0; i < p2->character->getColBoxes().size(); i++){
            if(p1->character->getColBoxes()[i]->collide(p2->character->getColBoxes()[j])){
                if(p1->character->get_left()){
                    w = std::max(w, (p1->character->getColBoxes()[i]->get_x() + p1->character->getColBoxes()[i]->get_w()) - p2->character->getColBoxes()[j]->get_x());
                }else{
                    w = std::min(w, p1->character->getColBoxes()[i]->get_x() - (p2->character->getColBoxes()[j]->get_x() + p2->character->getColBoxes()[j]->get_w()));
                }
            }
        }
    }
    if(w){
        p1->character->move(p1->character->get_x() - w / 2, p1->character->get_y());
        p2->character->move(p2->character->get_x() + w / 2, p2->character->get_y());
    }

    //Character 1 wall collision.
    int x1 = 0, y1 = 0;
    for(unsigned int i = 0; i < p1->character->getColBoxes().size(); i++){
        //If character's collision box is beyond the left stage boundary.
        if(p1->character->getColBoxes()[i]->get_x() < 0){
            //Find the greatest abs. collision width.
            x1 = std::min(x1, p1->character->getColBoxes()[i]->get_x());
        }
        //If character's collision box is beyond the right stage boundary.
        if(p1->character->getColBoxes()[i]->get_x() + p1->character->getColBoxes()[i]->get_w() > STAGE_WIDTH){
            //Find the greatest abs. collision width.
            x1 = std::max(x1, p1->character->getColBoxes()[i]->get_x() + p1->character->getColBoxes()[i]->get_w() - STAGE_WIDTH);
        }
        //If character's collision box is beyond the stage floor.
        if(p1->character->getColBoxes()[i]->get_y() + p1->character->getColBoxes()[i]->get_h() > STAGE_HEIGHT){
            //Find the greatest abs. collision height.
            y1 = std::max(y1, p1->character->getColBoxes()[i]->get_y() + p1->character->getColBoxes()[i]->get_h() - STAGE_HEIGHT);
        }
    }
    if(y1){
        p1->character->set_dy(0);
    }
    //Character 2 wall collision.
    int x2 = 0, y2 = 0;
    for(unsigned int i = 0; i < p2->character->getColBoxes().size(); i++){
        //If character's collision box is beyond the left stage boundary.
        if(p2->character->getColBoxes()[i]->get_x() < 0){
            //Find the greatest absolute collision width.
            x2 = std::min(x2, p2->character->getColBoxes()[i]->get_x());
        }
        //If character's collision box is beyond the right stage boundary.
        if(p2->character->getColBoxes()[i]->get_x() + p2->character->getColBoxes()[i]->get_w() > STAGE_WIDTH){
            //Find the greatest absolute collision width.
            x2 = std::max(x2, p2->character->getColBoxes()[i]->get_x() + p2->character->getColBoxes()[i]->get_w() - STAGE_WIDTH);
        }
        //If character's collision box is beyond the stage floor.
        if(p2->character->getColBoxes()[i]->get_y() + p2->character->getColBoxes()[i]->get_h() > STAGE_HEIGHT){
            //Find the greatest absolute collision height.
            y2 = std::max(y2, p2->character->getColBoxes()[i]->get_y() + p2->character->getColBoxes()[i]->get_h() - STAGE_HEIGHT);
        }
    }
    if(y2){
        p2->character->set_dy(0);
    }

    if(x1 || y1 || x2 || y2){
        p1->character->move(p1->character->get_x() - x1, p1->character->get_y() - y1);
        p2->character->move(p2->character->get_x() - x2, p2->character->get_y() - y2);
    }

    //TODO remove from decollide?
    //Side checking.
    if(p1->character->get_x() < p2->character->get_x()){
        p1->character->set_left(true);
        p2->character->set_left(false);
    }
    if(p1->character->get_x() > p2->character->get_x()){
        p1->character->set_left(false);
        p2->character->set_left(true);
    }

    /*CHARACTER COLLISION*/
    if(x1 || x2){
        w = 0;
        for(unsigned int i = 0; i < p1->character->getColBoxes().size(); i++){
            for(unsigned int j = 0; i < p2->character->getColBoxes().size(); i++){
                if(p1->character->getColBoxes()[i]->collide(p2->character->getColBoxes()[j])){
                    if(p1->character->get_left()){
                        w = std::max(w, (p1->character->getColBoxes()[i]->get_x() + p1->character->getColBoxes()[i]->get_w()) - p2->character->getColBoxes()[j]->get_x());
                    }else{
                        w = std::min(w, p1->character->getColBoxes()[i]->get_x() - (p2->character->getColBoxes()[j]->get_x() + p2->character->getColBoxes()[j]->get_w()));
                    }
                }
            }
        }
        if(w){
            if(std::abs(x1) > std::abs(x2)){
                if(p1->character->get_left()){
                    p2->character->move(p2->character->get_x() + w, p2->character->get_y());
                }else{
                    p2->character->move(p2->character->get_x() + w, p2->character->get_y());
                }
            }else{
                if(p1->character->get_left()){
                    p1->character->move(p1->character->get_x() - w, p1->character->get_y());
                }else{
                    p1->character->move(p1->character->get_x() - w, p1->character->get_y());
                }
            }
        }
    }

    return;
}

void VersusState::load(){
    //TODO
    std::cout << "VERSUS STATE" << std::endl;

    for(unsigned int i = 0; i < ACTIVE_PLAYERS && i < game->getPlayersList().size(); i++){
        //TODO start characters closer together so origin point for characters not in middle?
        //TODO Let players choose active slot
        active[i] = game->getPlayersList()[i];
        if(i < (ACTIVE_PLAYERS + 1) / 2){
            //First half of players start facing left.
            active[i]->character = new Character((i + 1) * STAGE_WIDTH / (ACTIVE_PLAYERS + 1), STAGE_HEIGHT);
        }else{
            //Last half of players start facing right.
            active[i]->character = new Character((i + 1) * STAGE_WIDTH / (ACTIVE_PLAYERS + 1), STAGE_HEIGHT);
        }
        //TODO dynamic starting position
        active[i]->character->addColBox(-50, 0, 100, 100 - 10 * i);
    }

    return;
}

std::string VersusState::name(){
    return "VersusState";
}

void VersusState::pause(){
    //TODO pause timers and shit?
    
    return;
}

void VersusState::render(){
    //TODO
    //TODO fix clear stuff?
    //TODO clear color?
    SDL_RenderClear(game->gameWindow.renderer);
    
    for(unsigned int i = 0; i < ACTIVE_PLAYERS; i++){
        active[i]->character->render(game->gameWindow.renderer);
    }

    return;
}

void VersusState::resume(){
    //TODO
    return;
}

void VersusState::unload(){
    //TODO
    return;
}

void VersusState::update(){
    //TODO pass to character/player input handler?
    //TODO frame based logic
    //TODO get P1 P2 state for keyboard/controller
    //TODO Active players slots
    for(unsigned int i = 0; i < ACTIVE_PLAYERS; i++){
        if(active[i]->controller != nullptr){
            if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)){
                active[i]->character->set_dx(-10);
            }else if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)){
                active[i]->character->set_dx(10);
            }else{
                active[i]->character->set_dx(0);
            }
            if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_UP)){
                active[i]->character->set_dy(-10);
            }else if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)){
                //TODO if y + h >= STAGE_HEIGHT then crouch.
            }else if(active[i]->character->get_dy() < 10){
                active[i]->character->set_dy(active[i]->character->get_dy() + 1);
            }
        }else{
            const Uint8* keys = SDL_GetKeyboardState(NULL);

            //TODO Key player associations
            //If key pressed... else...
            /*
            if(keys[SDL_SCANCODE_]){

            }
            else{

            }
             */
            if(keys[SDL_SCANCODE_A] && !keys[SDL_SCANCODE_D]){
                active[i]->character->set_dx(-10);
            }else if(keys[SDL_SCANCODE_D] && !keys[SDL_SCANCODE_A]){
                active[i]->character->set_dx(10);
            }else{
                active[i]->character->set_dx(0);
            }

            if(keys[SDL_SCANCODE_S] && !keys[SDL_SCANCODE_W]){
                //CROUCH STUFF
            }else if(keys[SDL_SCANCODE_W] && !keys[SDL_SCANCODE_S]){
                active[i]->character->set_dy(-10);
            }else if(active[i]->character->get_dy() < 10){
                active[i]->character->set_dy(active[i]->character->get_dy() + 1);
            }
        }

        active[i]->character->update();
    }



    //TODO separate wall/character collision functions?
    //FIXME FUNCTION DOES NOT GUARANTEE PERFECT DECOLLISION FOR >2 CHARACTERS.
    //Handle character/wall collision.
    for(unsigned int i = 0; i < ACTIVE_PLAYERS - 1; i++){
        for(unsigned int j = i + 1; j < ACTIVE_PLAYERS; j++){
            decollide(active[i], active[j]);
        }
    }

    //TODO more update stuff

    return;
}

void VersusState::controllerAxisHandler(SDL_Event e){

    
    return;
}

void VersusState::controllerButtonHandler(SDL_Event e){
    //TODO multiple control method exclusion
    //TODO player differentiation

    switch(e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_A:
            break;

        case SDL_CONTROLLER_BUTTON_B:
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
            if(e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new VersusMenu());
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
            /*
                    case SDL_CONTROLLER_BUTTON_DPAD_UP:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                            break;
             */
        case SDL_CONTROLLER_BUTTON_MAX:
            break;

        default:
            break;
    }

    return;
}

//TODO CONTROLLER DEVICE handler

void VersusState::keyHandler(SDL_Event e){
    //TODO multiple control method exclusion
    //TODO player differentiation

    //TODO key repeat handling
    if(!e.key.repeat){
        //TODO state based handling
        //NOTE setup two control list profiles and when keyboard is pressed do stuff
        switch(e.key.keysym.sym){
                //TODO pass to character input handler?
            case SDLK_a:
                if(e.type == SDL_KEYDOWN){
                }
                break;

            case SDLK_d:
                if(e.type == SDL_KEYDOWN){
                }
                break;

            case SDLK_s:
                break;

            case SDLK_w:
                if(e.type == SDL_KEYDOWN){
                }
                break;

            default:
                break;
        }
    }
    return;
}

void VersusState::windowHandler(SDL_Event e){
    //TODO
    return;
}

