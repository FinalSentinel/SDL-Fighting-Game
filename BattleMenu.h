/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BattleMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 10:59 PM
 */

#ifndef BATTLEMENU_H
#define BATTLEMENU_H

#include "MenuState.h"

class BattleMenu: public MenuState{
private:

protected:

public:
	BattleMenu();

	virtual ~BattleMenu();
	
	

	std::string name();
	
	
	
	/*MENU FUNCTIONS*/
	void Versus();
	void Online();
	void Training();
	void Combos();
	void Tutorial();
	//   Back = MenuState::back()
};

#endif /* BATTLEMENU_H */

