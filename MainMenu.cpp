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

const char MainMenu::mainMenuMusic[] = "AEUHHH.wav";



MainMenu::MainMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    mainMenuSong = game->gameAudio.loadSong(mainMenuMusic);
    if(!mainMenuSong->get_song()){
        std::cerr << "ERROR loading main menu music"  << std::endl;
    }

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Battle", new Texture(), std::bind(&MainMenu::Battle, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Story", new Texture(), std::bind(&MainMenu::Story, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Gallery", new Texture(), std::bind(&MainMenu::Gallery, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Options", new Texture(), std::bind(&MainMenu::Options, this)));

    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Return to Title", new Texture(), std::bind(&MenuState::back, this)));
}

MainMenu::~MainMenu(void){
    game->gameAudio.unloadSong(mainMenuSong);
    if(mainMenuSong != nullptr){
        std::cerr << "ERROR menu song not unloaded correctly" <<std::endl;
    }
};

void MainMenu::load(void){
    MenuState::load();

    std::cout << "MAIN MENU" << std::endl;
    
    game->gameAudio.play(mainMenuSong);

    return;
}

std::string MainMenu::name(void) const{
    return "MainMenu";
}

void MainMenu::render(void) const{
    SDL_RenderClear(game->gameWindow.renderer);
    MenuState::render();

    if(mainMenuSong->get_song())
    return;
}

void MainMenu::resume(void){
    game->gameAudio.play(mainMenuSong);
    
    MenuState::resume();
    
    return;
}

void MainMenu::unload(void){
    MenuState::unload();
    
    return;
}

void MainMenu::controllerButtonHandler(void){
    if(game->e.cbutton.button != SDL_CONTROLLER_BUTTON_START){
        MenuState::controllerButtonHandler();
    }

    //TODO buttons

    return;
}

/*Menu functions*/
void MainMenu::Battle(void){
    std::cout << "Battle" << std::endl;
    game->pushState(new BattleMenu());

    return;
}

void MainMenu::Story(void){
    //TODO
    std::cout << "Story" << std::endl;
    game->pushState(new StoryMenu());

    return;
}

void MainMenu::Gallery(void){
    //TODO
    std::cout << "Gallery" << std::endl;
    game->pushState(new GalleryMenu());

    return;
}

void MainMenu::Options(void){
    //TODO
    std::cout << "Options" << std::endl;
    game->pushState(new OptionsMenu());

    return;
}
