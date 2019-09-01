/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "VideoMenu.h"

VideoMenu::VideoMenu(){
    dials[RESOLUTION] = game->gameWindow.get_resNum();
    dials[FULLSCREEN] = (int)game->gameWindow.get_fullscreen();
    dials[VSYNC] = (int)game->gameWindow.get_vSync();
    
    resolution = game->gameWindow.getResolution(dials[RESOLUTION]);
    
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]), new Texture(), std::bind(Resolution, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Fullscreen: " + std::string(dials[FULLSCREEN] ? "ON" : "OFF"), new Texture(), std::bind(Fullscreen, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("VSync: " + std::string(dials[VSYNC] ? "ON" : "OFF"), new Texture(), std::bind(VSync, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Default", new Texture(), std::bind(Default, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
    
    if(dials[FULLSCREEN]){
        selection = 1;
        index = 1;
    }
}

VideoMenu::~VideoMenu(){
}



void VideoMenu::load(){
    MenuState::load();
    
    if(dials[FULLSCREEN]){
        std::get<GRAPHIC>(options[0])->setRGBA(0x80, 0x80, 0x80);
    }
    
    return;
}

std::string VideoMenu::name(){
    return "VideoMenu";
}

void VideoMenu::update(){
    
    return;
}



void VideoMenu::controllerButtonHandler(){
    if(selection < 3 && (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT ||
            game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
            switch(selection){
                case RESOLUTION:{
                    if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT){
                        dials[RESOLUTION] = (game->gameWindow.totalResNum + dials[RESOLUTION] - 1) % game->gameWindow.totalResNum;
                    }
                    else{
                        dials[RESOLUTION] = (game->gameWindow.totalResNum + dials[RESOLUTION] + 1) % game->gameWindow.totalResNum;
                    }
                    resolution = game->gameWindow.getResolution(dials[RESOLUTION]);

                    std::get<TEXT>(options[selection]) = "Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]);
                    
                    break;
                }

                case FULLSCREEN:{
                    dials[FULLSCREEN] = !dials[FULLSCREEN];

                    std::get<TEXT>(options[selection]) = "Fullscreen: " + std::string(dials[FULLSCREEN] ? "ON" : "OFF");
                    
                    break;
                }

                case VSYNC:{
                    dials[VSYNC] = !dials[VSYNC];

                    std::get<TEXT>(options[selection]) = "VSync: " + std::string(dials[VSYNC] ? "ON" : "OFF");

                    break;
                }

                default:{
                    std::cerr << "ERROR bad selection" << std::endl;

                    break;
                }
            }
            std::get<GRAPHIC>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);
            std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
        }
    }
    if(game->gameWindow.get_fullscreen() && (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP ||
                                             game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
            std::get<GRAPHIC>(options[selection])->setRGBA();
            if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP){
                if(index > 1){
                    index--;
                }
                else if(selection == 1){
                    index = std::min((int) options.size() - 1, MAX_MENU_SIZE - 1);
                }
                
                selection = ((options.size() + selection - 3) % (options.size() - 1)) + 1;
            }
            else{
                if(index < MAX_MENU_SIZE - 1 && index < options.size() - 1){
                    index++;
                }
                else if(selection == options.size() - 1){
                    index = 1;
                }
                
                selection = ((options.size() + selection - 1) % (options.size() - 1)) + 1;
            }
            std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
            
        }
    }
    else{
        MenuState::controllerButtonHandler();
    }
    
    return;
}



/*MENU FUNCTIONS*/
void VideoMenu::Resolution(){
    if(!game->gameWindow.get_fullscreen()){
        game->gameWindow.swapResolution(dials[RESOLUTION]);
    }
    
    //TODO save resolution prompt
    
    return;
}

void VideoMenu::Fullscreen(){
    //FIXME strange behavior coming out of fullscreen
    std::cout<<dials[FULLSCREEN]<<std::endl;
    if((bool)dials[FULLSCREEN] != game->gameWindow.get_fullscreen()){
        game->gameWindow.swapDisplayMode();
        if(dials[FULLSCREEN]){
            std::get<GRAPHIC>(options[0])->setRGBA(0x80, 0x80, 0x80);
        }
        else{
            std::get<GRAPHIC>(options[0])->setRGBA(0xFF, 0xFF, 0xFF);
        }
    }
    
    //TODO save DisplayMode selection to file.
    
    //TODO save resolution prompt
    
    return;
}

void VideoMenu::VSync(){
    if((bool)dials[VSYNC] != game->gameWindow.get_vSync()){
        game->gameWindow.swapVSync();
    }
    //TODO display VSync selection
    //TODO save VSync selection to file.
    
    return;
}

void VideoMenu::Default(){
    //TODO load default settings
    return;
}

void VideoMenu::back(){
    //TODO save options to file.
    std::cout<<"test"<<std::endl;
    MenuState::back();

    return;
}
