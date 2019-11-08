/* 
 * File:   MusicSelectMenu.cpp
 * Author: Clayton
 * 
 * Created on October 7, 2019, 12:44 AM
 */

#include "MusicSelectMenu.h"

#include "VersusState.h"

const std::string MusicSelectMenu::menuText[MusicSelectMenu::numOptions]{
	"Song 1",
	"Song 2",
	"Song 3",
	"Song 4",
	"Song 5",
	"Song 6",
	"Back"
};

void(MusicSelectMenu::* const MusicSelectMenu::menuActions[MusicSelectMenu::numOptions])(void) = {
	&MusicSelectMenu::Set_music,
	&MusicSelectMenu::Set_music,
	&MusicSelectMenu::Set_music,
	&MusicSelectMenu::Set_music,
	&MusicSelectMenu::Set_music,
	&MusicSelectMenu::Set_music,
	&MenuState::back
};



MusicSelectMenu::MusicSelectMenu(int vMode, int vLevel): mode(vMode), level(vLevel){    
    for(int i = 0; i < numOptions; i++){
        options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
    }    
}

MusicSelectMenu::~MusicSelectMenu(void){
	//NONE
}

std::string MusicSelectMenu::name(void) const{
    return "MusicSelectMenu";
}

/*MENU FUNCTIONS*/
void MusicSelectMenu::Set_music(void){
    std::cout<<"set music: "<<menuText[selection]<<std::endl;
    
    game->pushState(new VersusState(mode, level, selection));
    
    return;
}
