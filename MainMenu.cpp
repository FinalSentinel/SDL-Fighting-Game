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

MainMenu::MainMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
     */

    options.emplace_back("Battle");
    actions.emplace_back(std::bind(Battle, this));

    options.emplace_back("Story");
    actions.emplace_back(std::bind(Story, this));

    options.emplace_back("Gallery");
    actions.emplace_back(std::bind(Gallery, this));

    options.emplace_back("Options");
    actions.emplace_back(std::bind(Options, this));

    options.emplace_back("Return to Title");
    actions.emplace_back(std::bind(Return_to_title, this));

    //actions[VERSUS] = std::bind(Versus, this);
    //actions[STORY] = std::bind(Story, this);
    //actions[GALLERY] = std::bind(Gallery, this);
    //actions[OPTIONS] = std::bind(Options, this);
    //actions[RETURN_TO_TITLE] = std::bind(Return_to_title, this);
}

MainMenu::~MainMenu(){
};

//MainMenu* MainMenu::instance();

void MainMenu::load(){
    MenuState::load();

    std::cout << "MAIN MENU" << std::endl;

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

void MainMenu::controllerButtonHandler(SDL_Event e){
    if(e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
        MenuState::controllerButtonHandler(e);
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

void MainMenu::Return_to_title(){
    std::cout << "Return to Title" << std::endl;
    game->popState();

    return;
}