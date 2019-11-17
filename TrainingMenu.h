#ifndef TRAININGMENU_H
#define TRAININGMENU_H

#include "MenuState.h"

class VersusState;

class TrainingMenu: public MenuState{
private:
	static const std::string menuText[];

	//TODO lambdas?
	static void(TrainingMenu::* const menuActions[])(void);

	VersusState* vstate;

protected:
	//NONE

public:
	enum Training_Options{
		RESET_POSITION,
		RESET_DISTANCE,
		RESET_SWAP,
		RESET_LOCK,
		BACK,
		numOptions
	};

	TrainingMenu(VersusState* versus);

	virtual ~TrainingMenu(void);

	std::string name(void) const;

	void save(void);

	/*MENU FUNCTIONS*/
	void Reset_position(void);
	void Reset_distance(void);
	void Reset_side(void);
	void Reset_lock(void);
	void back(void);
	/*
	HP Regen
	P1 HP
	P2 HP
	SP Regen
	P1 SP
	P2 SP
	Guard Guage
	P1 Guard
	P2 Guard
	Chip Setting
	Block Setting
	Block Stance
	Block Type
	Reversal Setting
	Counter Hit
	Opponent CPU
	Recovery Setting
	Recording Slot
	Playback Setting
	Character Specific Setting
	P1 Character
	P2 Character
	Stage
	Music

	//DISPLAY INFORMATION?
	*/
	//Back = MenuState::back(void);

};

#endif /* TRAININGMENU_H */

