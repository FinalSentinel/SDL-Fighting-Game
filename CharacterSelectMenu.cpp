/* 
 * File:   CharacterSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on September 23, 2019, 7:47 PM
 */

#include "CharacterSelectMenu.h"

#include "LevelSelectMenu.h"

#include "Player.h"

const std::string CharacterSelectMenu::menuText[CharacterSelectMenu::numOptions] = {
	"Character 1",
	"Character 2",
	"Character 3",
	"Character 4",
	"Character 5",
	"Lambda",
	"Back"
};

void(CharacterSelectMenu::* const CharacterSelectMenu::menuActions[CharacterSelectMenu::numOptions])(void) = {
	&CharacterSelectMenu::Set_character,
	&CharacterSelectMenu::Set_character,
	&CharacterSelectMenu::Set_character,
	&CharacterSelectMenu::Set_character,
	&CharacterSelectMenu::Set_character,
	&CharacterSelectMenu::Set_character,
	&MenuState::back
};



CharacterSelectMenu::CharacterSelectMenu(const int vMode): mode(vMode){
    for(int i = 0; i < numOptions; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
    }
}

CharacterSelectMenu::~CharacterSelectMenu(void){
	//NONE
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
    std::cout<<"set character: "<<menuText[selection]<<std::endl;
    
    //TODO Set Player character choice
    //TODO player based logic
    game->getPlayersList()[0]->set_character((CharacterID)selection);
    selected[0] = true;
    
    return;
}
