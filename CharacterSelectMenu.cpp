/* 
 * File:   CharacterSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on September 23, 2019, 7:47 PM
 */

#include "CharacterSelectMenu.h"

#include "LevelSelectMenu.h"

#include "Player.h"

CharacterSelectMenu::CharacterSelectMenu(const int vMode): mode(vMode){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    for(int i = 0; i < charNum; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
        (CHARACTER_LIST[i], new Texture(), std::bind(&CharacterSelectMenu::Set_character, this)));
    }
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
    
}

CharacterSelectMenu::~CharacterSelectMenu(void){
}

void CharacterSelectMenu::load(void){
    selected[0] = false;
    //XXX
    selected[1] = true;
    
    MenuState::load();
}

std::string CharacterSelectMenu::name(void) const{
    return "CharacterSelectMenu";
}

void CharacterSelectMenu::resume(void){
    load();
    
    MenuState::resume();
    
    return;
}

void CharacterSelectMenu::update(void){
    //TODO mode based loading for level/music?
    if(selected[0] == true && selected[1] == true){
        //TODO change to level select
        game->pushState(new LevelSelectMenu(mode));
    }
}

/*MENU FUNCTIONS*/
void CharacterSelectMenu::Set_character(void){
    std::cout<<"set character: "<<CHARACTER_LIST[selection]<<std::endl;
    
    //TODO Set Player character choice
    //TODO player based logic
    game->getPlayersList()[0]->set_character((CharacterID)selection);
    selected[0] = true;
    
    return;
}
