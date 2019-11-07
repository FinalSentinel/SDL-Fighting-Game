/* 
 * File:   LevelSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on October 2, 2019, 1:41 AM
 */

#include "LevelSelectMenu.h"

#include "MusicSelectMenu.h"

LevelSelectMenu::LevelSelectMenu(const int vMode): mode(vMode){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    for(int i = 0; i < levelNum; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        (LEVEL_LIST[i], new Texture(), std::bind(&LevelSelectMenu::Set_level, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
    
}

LevelSelectMenu::~LevelSelectMenu(void){
}

std::string LevelSelectMenu::name(void) const{
    return "LevelSelectMenu";
}

/*MENU FUNCTIONS*/
void LevelSelectMenu::Set_level(void){
    std::cout<<"set level: "<<LEVEL_LIST[selection]<<std::endl;
    
    game->pushState(new MusicSelectMenu(mode, selection));
    
    return;
}
