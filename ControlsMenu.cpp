/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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

const char ControlsMenu::controlFormat[] = "controlFormat.txt";

const char ControlsMenu::controlDefault[] = "controlConfigDefault.txt";

ControlsMenu::ControlsMenu(){
    //    for(int i = 0; i < game->MAX_PLAYERS; i++){
    //        altSelection[i] = 0;
    //        altIndex[i] = 0;
    //        config[i] = false;
    //        configNum[i] = 0;
    //    

    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
     */

    options.emplace_back(std::tuple < std::string, Texture*, std::function<void()> >
            ("Quick Config", new Texture(), std::bind(Quick_config, this)));

    //TODO do better
    game->fileI.open(controlFormat);
    if(!game->fileI.is_open()){
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    else{
        int i = 0;
        while(game->fileI.getline(hold, 32)){
            options.emplace_back(std::tuple < std::string, Texture*, std::function<void()>>
                    (std::string(hold) + ": " + game->getPlayersList()[0]->controls[i], new Texture(), std::bind(none, this)));
            i++;
        }
    }
    game->fileI.close();
    //TODO setup keyboard stuff

    options.emplace_back(std::tuple < std::string, Texture*, std::function<void()> >
            ("Default", new Texture(), std::bind(Default, this)));

    options.emplace_back(std::tuple < std::string, Texture*, std::function<void()> >
            ("Back", new Texture(), std::bind(back, this)));
}

ControlsMenu::~ControlsMenu(){
}

std::string ControlsMenu::name(){
    return "ControlsMenu";
}

void ControlsMenu::reload(){
    //TODO DO BETTER
    int n = 1;
    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        while(game->fileI.getline(hold, 32) && hold[0] != '!'){
            //TODO better loop check
            std::get<TEXT>(options[n]) = std::string(hold) + ": ";
            n++;
        }
        hold[0] = ' ';
    }
    else{
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    game->fileI.close();
    for(int i = 0; i < versusControlsNum; i++){
        std::get<TEXT>(options[i + 1]).append(game->getPlayersList()[0]->controls[i]);
    }
    
    //TODO keyboard stuff

    for(int i = 0; i < versusControlsNum; i++){
        std::get<GRAPHIC>(options[i + 1])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i + 1]), 100);
    }
    if(!options.empty()){
        std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
    }

    return;
}

void ControlsMenu::render(){
    MenuState::render();

    if(config[0]){
        //Menu x position is always at 3/5 of window width.
        int x = game->gameWindow.getWidth() / 5;
        int y = game->gameWindow.getHeight() / 3;

        prompt[0].render(game->gameWindow.renderer, x, y, x * 3, y);
    }

    return;
}

void ControlsMenu::setButton(Player* p, int n, std::string button){
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

void ControlsMenu::update(){
    //NONE

    return;
}

void ControlsMenu::controllerAxisHandler(){
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
                    for(int i = 0; i < RECORD - TAUNT; i++){
                        game->fileI.getline(hold, 32);
                    }
                    configNum[0] = RECORD;
                }
                else if(configNum[0] == versusControlsNum){
                    config[0] = false;

                    game->fileI.close();

                    game->getPlayersList()[0]->saveControls();

                    reload();

                    for(int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }
                
                game->fileI.getline(hold, 32);
                prompt[0].loadText(game->gameWindow.renderer, std::string(hold), 100);
            }
        }
    }
    else{
        MenuState::controllerAxisHandler();
    }

    return;
}

void ControlsMenu::controllerButtonHandler(){
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
                    for(int i = 0; i < RECORD - TAUNT; i++){
                        game->fileI.getline(hold, 32);
                    }
                    configNum[0] = RECORD;
                }
                else if(configNum[0] == versusControlsNum - 1){
                    config[0] = false;

                    game->fileI.close();

                    game->getPlayersList()[0]->saveControls();

                    reload();

                    for(int i = 0; i < options.size(); i++){
                        //TODO get RGBA
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                }
                
                game->fileI.getline(hold, 32);
                prompt[0].loadText(game->gameWindow.renderer, std::string(hold), 100);
            }
            else{
                config[0] = false;

                game->fileI.close();

                for(int i = 0; i < options.size(); i++){
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
void ControlsMenu::Quick_config(){
    std::cout << "Quick Config" << std::endl;

    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        config[0] = true;
        configNum[0] = PUNCH;

        for(int i = 0; i < options.size(); i++){
            //TODO get RGBA
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
        for(int i = 0; i <= PUNCH; i++){
            game->fileI.getline(hold, 32);
        }
        prompt[0].loadText(game->gameWindow.renderer, std::string(hold), 100);
    }
    else{
        game->fileI.close();
        std::cerr << "ERROR unable to open controls fileI." << std::endl;
    }

    return;
}

void ControlsMenu::Default(){
    std::cout << "Default" << std::endl;

    game->fileI.open(controlDefault);

    if(!game->fileI.is_open()){
        std::cerr << "ERROR cannot open controls default." << std::endl;
        
        game->getPlayersList()[0]->saveControls();
    }
    else{
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

//void ControlsMenu::back(){
//    for(int i = 0; i < game->getPlayersList().size(); i++){
//        game->getPlayersList()[i]->saveControls();

//        reload();
//    }
//
//    MenuState::back();
//
//    return;
//}

void ControlsMenu::none(){
    return;
}