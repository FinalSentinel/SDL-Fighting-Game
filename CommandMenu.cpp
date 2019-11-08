/* 
 * File:   CommandMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 9:53 PM
 */

#include "CommandMenu.h"

const std::string CommandMenu::menuText[CommandMenu::numOptions] = {
	"CHARACTER NAME",
	"Move 1",
	"Move 2",
	"Move 3",
	"Back"
};

void(CommandMenu::* const CommandMenu::menuActions[CommandMenu::numOptions])(void) = {
	&CommandMenu::none,
	&CommandMenu::Play,
	&CommandMenu::Play,
	&CommandMenu::Play,
	&MenuState::back
};



CommandMenu::CommandMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

CommandMenu::~CommandMenu(void){
	//NONE
}

std::string CommandMenu::name(void) const{
    return "CommandMenu";
}

/*MENU FUNCTIONS*/
void CommandMenu::Play(void){
    //TODO
	std::cout << "Play Move: " << menuText[selection] << std::endl;

    return;
}

void CommandMenu::none(void){
    return;
}
