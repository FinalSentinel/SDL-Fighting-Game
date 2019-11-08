/* 
 * File:   LevelSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on October 2, 2019, 1:41 AM
 */

#include "LevelSelectMenu.h"

#include "MusicSelectMenu.h"

const std::string LevelSelectMenu::menuText[LevelSelectMenu::numOptions] = {
	"Level 1",
	"Level 2",
	"Level 3",
	"Level 4",
	"Level 5",
	"Level 6",
	"Back"
};

void(LevelSelectMenu::* const LevelSelectMenu::menuActions[LevelSelectMenu::numOptions])(void) = {
	&LevelSelectMenu::Set_level,
	&LevelSelectMenu::Set_level,
	&LevelSelectMenu::Set_level,
	&LevelSelectMenu::Set_level,
	&LevelSelectMenu::Set_level,
	&LevelSelectMenu::Set_level,
	&MenuState::back
};



LevelSelectMenu::LevelSelectMenu(const int vMode): mode(vMode){    
    for(int i = 0; i < numOptions; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
    }
}

LevelSelectMenu::~LevelSelectMenu(void){
	//NONE
}

std::string LevelSelectMenu::name(void) const{
    return "LevelSelectMenu";
}

/*MENU FUNCTIONS*/
void LevelSelectMenu::Set_level(void){
    std::cout<<"set level: "<<menuText[selection]<<std::endl;
    
    game->pushState(new MusicSelectMenu(mode, selection));
    
    return;
}
