/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MainMenu.cpp
 * Author: Clayton
 * 
 * Created on August 23, 2019, 3:45 PM
 */

#include "MainMenu.h"

#include "BattleMenu.h"
#include "OptionsMenu.h"
#include "GalleryMenu.h"
#include "StoryMenu.h"
#include "Song.h"



const char MainMenu::mainMenuMusic[] = "AEUHHH.mp3";



MainMenu::MainMenu(){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    mainMenuSong = game->gameAudio.loadSong(mainMenuMusic);
    if(!mainMenuSong->get_song()){
        std::cerr << "ERROR loading main menu music"  << std::endl;
    }

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Battle", new Texture(), std::bind(Battle, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Story", new Texture(), std::bind(Story, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Gallery", new Texture(), std::bind(Gallery, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Options", new Texture(), std::bind(Options, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Return to Title", new Texture(), std::bind(back, this)));
}

MainMenu::~MainMenu(){
    game->gameAudio.unloadSong(mainMenuSong);
    if(mainMenuSong != nullptr){
        std::cerr << "ERROR menu song not unloaded correctly" <<std::endl;
    }
};



void MainMenu::load(){
    MenuState::load();

    std::cout << "MAIN MENU" << std::endl;
    
    //TODO song play function Audio class
    Mix_FadeInMusicPos(mainMenuSong->get_song(), -1, 30, 0);

    return;
}

std::string MainMenu::name(){
    return "MainMenu";
}

void MainMenu::render(){
    SDL_RenderClear(game->gameWindow.renderer);
    MenuState::render();

    return;
}

void MainMenu::unload(){
    Mix_FadeOutMusic(30);
    
    MenuState::unload();
    
    return;
}



void MainMenu::controllerButtonHandler(){
    if(game->e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
        MenuState::controllerButtonHandler();
    }

    //TODO buttons

    return;
}



/*Menu functions*/
void MainMenu::Battle(){
    std::cout << "Battle" << std::endl;
    game->pushState(new BattleMenu());

    return;
}

void MainMenu::Story(){
    //TODO
    std::cout << "Story" << std::endl;
    game->pushState(new StoryMenu());

    return;
}

void MainMenu::Gallery(){
    //TODO
    std::cout << "Gallery" << std::endl;
    game->pushState(new GalleryMenu());

    return;
}

void MainMenu::Options(){
    //TODO
    std::cout << "Options" << std::endl;
    game->pushState(new OptionsMenu());

    return;
}