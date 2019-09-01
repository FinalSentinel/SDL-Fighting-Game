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
    
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Resolution", new Texture(), std::bind(Resolution, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Fullscreen", new Texture(), std::bind(Fullscreen, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("VSync", new Texture(), std::bind(VSync, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Default", new Texture(), std::bind(Default, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
}

VideoMenu::VideoMenu(const VideoMenu& orig){
}

VideoMenu::~VideoMenu(){
}



std::string VideoMenu::name(){
    return "VideoMenu";
}



void VideoMenu::controllerButtonHandler(){
    if(selection < 3){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
            switch(game->e.cbutton.button){
                case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
                    switch(selection){
                        case RESOLUTION:{
                            dials[RESOLUTION] = (game->gameWindow.totalResNum + dials[RESOLUTION] - 1) % game->gameWindow.totalResNum;
                            
                            break;
                        }
                        
                        case FULLSCREEN:{
                            dials[FULLSCREEN] = !dials[FULLSCREEN];
                            
                            break;
                        }
                        
                        case VSYNC:{
                            dials[VSYNC] = !dials[VSYNC];
                            
                            break;
                        }
                        
                        default:{
                            std::cerr<<"ERROR bad selection"<<std::endl;
                                    
                            break;
                        }
                    }
                    
                    break;
                }
                case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
                    switch(selection){
                        case RESOLUTION:{
                            dials[RESOLUTION] = (game->gameWindow.totalResNum + dials[RESOLUTION] + 1) % game->gameWindow.totalResNum;
                            
                            break;
                        }
                        
                        case FULLSCREEN:{
                            dials[FULLSCREEN] = !dials[FULLSCREEN];
                            
                            break;
                        }
                        
                        case VSYNC:{
                            dials[VSYNC] = !dials[VSYNC];
                            
                            break;
                        }
                        
                        default:{
                            std::cerr<<"ERROR bad selection"<<std::endl;
                                    
                            break;
                        }
                    }
                    
                    break;
                }
                default:{
                    MenuState::controllerButtonHandler();
                    
                    break;
                }
            }
        }
    }
    else{
        MenuState::controllerButtonHandler();
    }
    
    return;
}



/*MENU FUNCTIONS*/
void VideoMenu::Resolution(){
    //TODO
    
    return;
}

void VideoMenu::Fullscreen(){
    game->gameWindow.swapDisplayMode();
    
    //TODO display DisplayMode selection
    //TODO save DisplayMode selection to file.
    
    //TODO save resolution prompt
    
    return;
}

void VideoMenu::VSync(){
    game->gameWindow.swapVSync();
    
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