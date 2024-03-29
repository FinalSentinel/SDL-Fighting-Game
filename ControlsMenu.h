/* 
 * File:   ControlsMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 11:50 PM
 */

#ifndef CONTROLSMENU_H
#define CONTROLSMENU_H

#include "MenuState.h"
#include "Player.h"



class ControlsMenu: public MenuState{
private:
	static const char controlDefault[];

	static const std::string menuText[];

	//TODO lambdas?
	static void(ControlsMenu::* const menuActions[])(void);

	std::string controlMap[Player::num_versusActions];

protected:
	bool config[MAX_PLAYERS];
	
	int configNum[MAX_PLAYERS];
	
	Texture prompt[MAX_PLAYERS];

public:
	enum ControlsOptions{
		QUICK_CONFIG,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		PUNCH,
		KICK,
		HEAVY,
		SPECIAL,
		P_K,
		P_S,
		K_H,
		P_K_H,
		P_K_H_S,
		TAUNT,
		RECORD,
		PLAY,
		RESET,
		PAUSE,
		DEFAULT,
		BACK,
		num_ControlsOptions
	};

	

	ControlsMenu(void);

	virtual ~ControlsMenu(void);
	
	std::string name(void) const;
	
	void reloadMenu(void);
	
	void render(void) const;
	
	void update(void);
	
	void controllerAxisHandler(void);
	
	void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	void Quick_config(void);
	void Default(void);
	//void back(void);
	void none(void);

};

#endif /* CONTROLSMENU_H */

