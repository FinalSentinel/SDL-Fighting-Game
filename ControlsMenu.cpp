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
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Quick Config", new Texture(), std::bind(Quick_config, this)));

    //TODO do better
    game->fileI.open(controlFormat);
    if(!game->fileI.is_open()){
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    else{
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check            
            options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
            (std::string(hold) + ": ", new Texture(), std::bind(none, this)));
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
            std::get<TEXT>(options[i]).append(std::string(hold) + "/");
            i++;
        }
        i = 1;
        while(game->fileI.getline(hold, 32)){
            std::get<TEXT>(options[i]).append(std::string(hold));
            i++;
        }
    }
    game->fileI.close();

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Default", new Texture(), std::bind(Default, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(Back, this)));
}

ControlsMenu::ControlsMenu(const ControlsMenu& orig){
}

ControlsMenu::~ControlsMenu(){
}

void ControlsMenu::loadButtons(){
    //TODO DO BETTER
    int i = 1;
    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        char hold[32];
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            std::get<TEXT>(options[i]) = std::string(hold) + ": ";
            i++;
        }
    }
    else{
        std::cerr << "ERROR unable to open control format fileI." << std::endl;
    }
    game->fileI.close();
    i = 1;
    game->fileI.open(controlConfig);
    if(game->fileI.is_open()){
        char hold[32];
        while(game->fileI.getline(hold, 32)){
            //TODO better loop check
            if(std::string(hold) == "") break;
            std::get<TEXT>(options[i]).append(std::string(hold) + "/");
            i++;
        }
        i = 1;
        while(game->fileI.getline(hold, 32)){
            std::get<TEXT>(options[i]).append(std::string(hold));
            i++;
        }
    }
    else{
        std::cerr << "ERROR unable to open control config fileI." << std::endl;
    }
    game->fileI.close();

    for(int i = 1; i < 19; i++){
        std::get<GRAPHIC>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
    }
    if(!options.empty()){
        std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
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

        for(int i = 0; i < options.size(); i++){
            //TODO get RGBA
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
        }
        std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
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
    //TODO player differentiation
    if(selection >= 1 && selection <= 18 &&
       e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_UP && e.cbutton.button != SDL_CONTROLLER_BUTTON_DPAD_DOWN){
        if(e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
            switch(e.cbutton.button){
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
                    selection = 0;
                    break;
                }

                default:
                {
                    if(selection >= 5 && selection <= 17){
                        std::cout << "Set Button" << std::endl;
                        //TODO
                    }
                    break;
                }
            }
        }
    }
    else if(config){
        if(e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
            std::cout << SDL_GameControllerGetStringForButton(SDL_GameControllerButton(e.cbutton.button)) << std::endl;
            game->fileI.getline(hold, 32);
            configPrompt.loadText(game->gameWindow.renderer, std::string(hold), 100);
            configNum++;
        }
        else{
            config = false;

            //TODO Set player controls
            //TODO save controls to file

            game->fileI.close();

            for(int i = 0; i < options.size(); i++){
                //TODO get RGBA
                std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
            }
            std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
        }
    }
    else{
        MenuState::controllerButtonHandler(e);
    }

    return;
}

/*MENU FUNCTIONS*/
void ControlsMenu::Quick_config(){
    std::cout << "Set Buttons" << std::endl;

    game->fileI.open(controlFormat);
    if(game->fileI.is_open()){
        config = true;
        configNum = 5;

        for(int i = 0; i < options.size(); i++){
            //TODO get RGBA
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
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

void ControlsMenu::Default(){
    std::cout << "Default" << std::endl;

    //TODO YES/NO option

    game->fileI.open(controlDefault);

    if(!game->fileI.is_open()){
        std::cerr << "ERROR cannot open controls default." << std::endl;
    }
    else if(std::remove(controlConfig.c_str()) != 0){
        std::cerr << "ERROR cannot delete controls config file" << std::endl;
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

void ControlsMenu::none(){
    return;
}