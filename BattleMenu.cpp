/* 
 * File:   BattleMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 10:59 PM
 */

#include "BattleMenu.h"

#include "CharacterSelectState.h"

const std::string BattleMenu::menuText[numOptions] = {
	"Versus",
	"Online",
	"Training",
	"Combos",
	"Tutorial",
	"Back"
};

void(BattleMenu::* const BattleMenu::menuActions[numOptions])(void) = {
	&BattleMenu::Char_select,
	&BattleMenu::Char_select,
	&BattleMenu::Char_select,
	&BattleMenu::Char_select,
	&BattleMenu::Char_select,
	&MenuState::back
};



BattleMenu::BattleMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

BattleMenu::~BattleMenu(void){
	//NONE
}

std::string BattleMenu::name(void) const{
    return "BattleMenu";
}

/*MENU FUNCTIONS*/
void BattleMenu::Char_select(void){
    game->pushState(new CharacterSelectState(selection));
    std::cout<<game->get_back()->name()<<std::endl;

    return;
}
