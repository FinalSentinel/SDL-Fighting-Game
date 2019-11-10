#include "TrainingMenu.h"

const std::string TrainingMenu::menuText[TrainingMenu::numOptions] = {
	"TRAINING STUFF"
	"Back"
};

void(TrainingMenu::* const TrainingMenu::menuActions[TrainingMenu::numOptions])(void) = {
	&MenuState::TEMP,
	&MenuState::back
};



TrainingMenu::TrainingMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
}

TrainingMenu::~TrainingMenu(void){
	//NONE
}

std::string TrainingMenu::name(void) const{
	return "TrainingMenu";
}

/*MENU FUNCTIONS*/
