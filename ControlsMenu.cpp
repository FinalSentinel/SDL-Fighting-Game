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

ControlsMenu::ControlsMenu(): config(false){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
     */

    options.emplace_back("Configure Buttons");
    actions.emplace_back(std::bind(Config_buttons, this));

    game->file.open(controlFormat);
    if(game->file.is_open()){
        char hold[32];
        while(game->file.getline(hold, 32)){
            options.emplace_back(hold);
            actions.emplace_back(std::bind(Set_button, this));
        }
    }
    else{
        game->file.close();
        std::cerr << "ERROR unable to open control format file." << std::endl;
    }

    options.emplace_back("Default");
    actions.emplace_back(std::bind(Default, this));

    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

ControlsMenu::ControlsMenu(const ControlsMenu& orig){
}

ControlsMenu::~ControlsMenu(){
}

std::string ControlsMenu::name(){
    return "ControlsMenu";
}

void ControlsMenu::render(){
    MenuState::render();

    if(config){
        //Menu x position is always at 3/5 of window width.
        int x = game->gameWindow.get_w() / 5;
        //Menu height is the number of window height divided by numOptions + 2,
        //therefore equal blank space above and below.  Will implement scrolling.
        int y = game->gameWindow.get_h() / 3;

        configPrompt.loadText(game->gameWindow.renderer, options[configNum], 100);
        configPrompt.render(game->gameWindow.renderer, x, y, x * 3, y);
    }

    return;
}

void ControlsMenu::update(){
    if(configNum  == options.size() - 2){
        config = false;

        //TODO Set player controls
        //TODO save controls to file

        game->file.close();

        for(int i = 0; i < buttons.size(); i++){
            //TODO get RGBA
            buttons[i]->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    return;
}

void ControlsMenu::controllerAxisHandler(SDL_Event e){
    //TODO multiple control method exclusion
    //TODO player differentiation
    //TODO menu mapping
    //TODO make options files
    if(!config){
        MenuState::controllerAxisHandler(e);
    }
    else{
        if(e.caxis.value > 30000){
            if(e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT || e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT){
                //TODO set stuff
                configNum++;
                //XXX
                game->file << SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(e.caxis.axis)) << std::endl;
            }
        }
    }

    return;
}

void ControlsMenu::controllerButtonHandler(SDL_Event e){
    //TODO multiple control method exclusion
    //TODO player differentiation
    //TODO menu mapping
    //TODO make options files
    if(e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
        if(!config){
            MenuState::controllerButtonHandler(e);
        }
        else{
  //          if(e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
                std::cout  << SDL_GameControllerGetStringForButton(SDL_GameControllerButton(e.cbutton.button)) << std::endl;
                configNum++;
                //XXX
                game->file << SDL_GameControllerGetStringForButton(SDL_GameControllerButton(e.cbutton.button)) << std::endl;
   //         }
        }
    }

    return;
}

/*MENU FUNCTIONS*/
void ControlsMenu::Config_buttons(){
    std::cout << "Set Buttons" << std::endl;

    game->file.open(controlConfig);
    if(game->file.is_open()){
        config = true;
        configNum = 1;

        for(int i = 0; i < buttons.size(); i++){
            //TODO get RGBA
            buttons[i]->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    else{
        game->file.close();
        std::cerr << "ERROR unable to  open controls file." << std::endl;
    }

    return;
}

void ControlsMenu::Set_button(){
    std::cout << "Set Button" << std::endl;


    return;
}

void ControlsMenu::Default(){
    std::cout << "Default" << std::endl;
    //TODO load default button config.

    return;
}

void ControlsMenu::Back(){
    std::cout << "Options" << std::endl;
    game->popState();

    return;
}