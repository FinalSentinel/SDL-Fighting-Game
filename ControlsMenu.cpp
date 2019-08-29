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

//TODO Keyboard controls
//TODO Menu controls

ControlsMenu::ControlsMenu(): config(false){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
     */

    options.emplace_back("Quick Config");
    actions.emplace_back(std::bind(Config_buttons, this));

    //TODO do better
    game->fileI.open(controlFormat);
    if(!game->fileI.is_open()){
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    else{
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            options.emplace_back(std::string(hold) + ": ");
            actions.emplace_back(std::bind(Set_button, this));
        }
    }
    game->fileI.close();
    
    game->fileI.open(controlConfig);
    if(!game->fileI.is_open()){
        std::cerr << "ERROR unable to open control config fileI." << std::endl;
    }
    else{
        int i = 1;
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            if(std::string(hold) == "") break;
            options[i].append(std::string(hold) + "/");
            i++;
        }
        i = 1;
        while(game->fileI.getline(hold, 32)){
            options[i].append(std::string(hold));
            i++;
        }
    }
    game->fileI.close();

    options.emplace_back("Default");
    actions.emplace_back(std::bind(Default, this));

    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

ControlsMenu::ControlsMenu(const ControlsMenu& orig){
}

ControlsMenu::~ControlsMenu(){
}

void ControlsMenu::loadButtons(){
    //TODO DO BETTER
    options.clear();
    
    options.emplace_back("Quick Config");

    //TODO do better
    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        char hold[32];
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            options.emplace_back(std::string(hold) + ": ");
        }
    }
    else{
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    game->fileI.close();
    game->fileI.open(controlConfig);
    if(game->fileI.is_open()){
        char hold[32];
        int i = 1;
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            if(std::string(hold) == "") break;
            options[i].append(std::string(hold) + "/");
            i++;
        }
        i = 1;
        while(game->fileI.getline(hold, 32)){
            options[i].append(std::string(hold));
            i++;
        }
    }
    else{
        std::cerr << "ERROR unable to open control config fileI." << std::endl;
    }
    game->fileI.close();

    options.emplace_back("Default");

    options.emplace_back("Back");
    
    for(int i = 0; i < buttons.size(); i++){
        buttons[i]->loadText(game->gameWindow.renderer, options[i], 100);
    }
    if(!buttons.empty()){
        buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
    }
    
    return;
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

        configPrompt.render(game->gameWindow.renderer, x, y, x * 3, y);
    }

    return;
}

void ControlsMenu::update(){
    if(configNum >= 8 && configNum <= 13){
        for(int i = 0; i < 6; i++){
            game->fileI.getline(hold, 32);
        }
        configNum = 14;
    }
    if(configNum == options.size() - 3){
        config = false;

        //TODO Set player controls
        //TODO save controls to file
        
        game->fileI.close();

        for(int i = 0; i < buttons.size(); i++){
            //TODO get RGBA
            buttons[i]->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
        }
        buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
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
                std::cout << SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis(e.caxis.axis)) << std::endl;
                game->fileI.getline(hold, 32);
                configPrompt.loadText(game->gameWindow.renderer, std::string(hold), 100);
                configNum++;
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
            if(e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
                std::cout  << SDL_GameControllerGetStringForButton(SDL_GameControllerButton(e.cbutton.button)) << std::endl;
                game->fileI.getline(hold, 32);
                configPrompt.loadText(game->gameWindow.renderer, std::string(hold), 100);
                configNum++;
            }
            else{
                config = false;

                //TODO Set player controls
                //TODO save controls to file

                game->fileI.close();

                for(int i = 0; i < buttons.size(); i++){
                    //TODO get RGBA
                    buttons[i]->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                }
                buttons[selection]->setRGBA(0xFF, 0x80, 0x00);
            }
        }
    }

    return;
}

/*MENU FUNCTIONS*/
void ControlsMenu::Config_buttons(){
    std::cout << "Set Buttons" << std::endl;

    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        config = true;
        configNum = 5;

        for(int i = 0; i < buttons.size(); i++){
            //TODO get RGBA
            buttons[i]->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
        for(int i = 0; i < 5; i++){
            game->fileI.getline(hold, 32);
        }
        configPrompt.loadText(game->gameWindow.renderer, std::string(hold), 100);
    }
    else{
        game->fileI.close();
        std::cerr << "ERROR unable to open controls fileI." << std::endl;
    }

    return;
}

void ControlsMenu::Set_button(){
    std::cout << "Set Button" << std::endl;


    return;
}

void ControlsMenu::Default(){
    std::cout << "Default" << std::endl;
    
    //TODO YES/NO option
    
    game->fileI.open(controlDefault);
        
    if(!game->fileI.is_open()){
        std::cerr << "ERROR cannot open controls default." << std::endl;
    }
    else if(std::remove(controlConfig.c_str()) != 0){
        std::cerr<<"ERROR cannot delete controls config file"<<std::endl;
    }
    else{
        game->fileO.open(controlConfig);
        game->fileO << game->fileI.rdbuf();

        game->fileO.close();
        game->fileI.close();

        loadButtons();
    }

    return;
}

void ControlsMenu::Back(){
    std::cout << "Options" << std::endl;
    game->popState();

    return;
}