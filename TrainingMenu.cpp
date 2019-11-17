#include "TrainingMenu.h"

#include "VersusState.h"

const std::string TrainingMenu::menuText[TrainingMenu::numOptions] = {
	"Reset Position: ",
	"Reset Distance: ",
	"Reset Side: ",
	"Lock Position: "
	"Back"
};

void(TrainingMenu::* const TrainingMenu::menuActions[TrainingMenu::numOptions])(void) = {
	&TrainingMenu::Reset_position,
	&TrainingMenu::Reset_distance,
	&TrainingMenu::Reset_side,
	&TrainingMenu::Reset_lock,
	&TrainingMenu::back
};



TrainingMenu::TrainingMenu(VersusState* versus): vstate(versus){
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

void TrainingMenu::save(void){
	game->fileO.open(vstate->get_trainingConfig());
	if(!game->fileO.is_open()){
		std::cerr << "ERROR cannot open training config file." << std::endl;
	}
	else{
		std::string hold = "";

		for(int i = 0; i < VersusState::num_Training; i++){
			hold.append(std::to_string(vstate->get_trainingSettings(i)) + '\n');
		}

		game->fileO << hold;

		game->fileO.close();
	}

	return;
}



/*MENU FUNCTIONS*/
void TrainingMenu::Reset_position(void){
	if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
		switch(game->e.cbutton.button){
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			{
				vstate->set_resetDistance(vstate->get_trainingSettings(VersusState::RESET_POSITION) - 1);
			}
			break;

			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			{
				vstate->set_resetDistance(vstate->get_trainingSettings(VersusState::RESET_POSITION) + 1);
			}
			break;
		}
	}

	std::get<TEXT>(options[RESET_POSITION]) = menuText[RESET_POSITION] + vstate->resetPositions[vstate->get_trainingSettings(VersusState::RESET_POSITION)];
	std::get<TEXTURE>(options[RESET_POSITION])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[RESET_POSITION]));

	return;
}

void TrainingMenu::Reset_distance(void){
	if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
		switch(game->e.cbutton.button){
			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			{
				vstate->set_resetDistance(vstate->get_trainingSettings(VersusState::RESET_DISTANCE) - 1);
			}
			break;

			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			{
				vstate->set_resetDistance(vstate->get_trainingSettings(VersusState::RESET_DISTANCE) + 1);
			}
			break;
		}
	}

	std::get<TEXT>(options[RESET_DISTANCE]) = menuText[RESET_DISTANCE] + vstate->resetDistances[vstate->get_trainingSettings(VersusState::RESET_DISTANCE)];
	std::get<TEXTURE>(options[RESET_DISTANCE])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[RESET_DISTANCE]));

	return;
}

void TrainingMenu::Reset_side(void){
	bool swap = !vstate->get_trainingSettings(VersusState::RESET_SWAP);

	vstate->set_resetSwap(swap);

	std::get<TEXT>(options[RESET_SWAP]) = menuText[RESET_SWAP] + (swap ? "ON" : "OFF");
	std::get<TEXTURE>(options[RESET_SWAP])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[RESET_SWAP]));

	return;
}

void TrainingMenu::Reset_lock(void){
	bool lock = !vstate->get_trainingSettings(VersusState::RESET_LOCK);
	vstate->set_resetLock(lock);

	std::get<TEXT>(options[RESET_LOCK]) = menuText[RESET_LOCK] + (lock ? "ON" : "OFF");
	std::get<TEXTURE>(options[RESET_LOCK])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[RESET_LOCK]));

	return;
}

void TrainingMenu::back(void){
	save();

	MenuState::back();

	return;
}
