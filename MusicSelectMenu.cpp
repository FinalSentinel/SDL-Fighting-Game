/* 
 * File:   MusicSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on October 7, 2019, 12:44 AM
 */

#include "MusicSelectMenu.h"

#include "VersusState.h"

MusicSelectMenu::MusicSelectMenu(int vMode, int vLevel): mode(vMode), level(vLevel){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    for(int i = 0; i < songNum; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        (MUSIC_LIST[i], new Texture(), std::bind(&MusicSelectMenu::Set_music, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
    
}

MusicSelectMenu::~MusicSelectMenu(void){
}

std::string MusicSelectMenu::name(void) const{
    return "MusicSelectMenu";
}

/*MENU FUNCTIONS*/
void MusicSelectMenu::Set_music(void){
    std::cout<<"set music: "<<MUSIC_LIST[selection]<<std::endl;
    
    game->pushState(new VersusState(mode, level, selection));
    
    return;
}
