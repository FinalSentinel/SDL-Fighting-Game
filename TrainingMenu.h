#ifndef TRAININGMENU_H
#define TRAININGMENU_H

#include "MenuState.h"



class TrainingMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(TrainingMenu::* const menuActions[])(void);

protected:
	//NONE

public:
	enum Training_Options{
		TRAINING_STUFF,
		BACK,
		numOptions
	};

	TrainingMenu(void);

	virtual ~TrainingMenu(void);

	std::string name(void) const;

	/*MENU FUNCTIONS*/
	//   Back = MenuState::back(void);

};

#endif /* TRAININGMENU_H */

