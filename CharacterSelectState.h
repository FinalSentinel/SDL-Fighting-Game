/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CharacterSelectState.h
 * Author: Clayton
 *
 * Created on September 14, 2019, 10:38 PM
 */

#ifndef CHARACTERSELECTSTATE_H
#define CHARACTERSELECTSTATE_H

#include "GameState.h"



class CharacterSelectState: public GameState{
private:

protected:
	int mode;

public:
	CharacterSelectState(int vMode);

	CharacterSelectState(const CharacterSelectState& orig);

	virtual ~CharacterSelectState();
	
	
	
	void load();

	std::string name();
	
	void resume();
	
	
	
	/*MENU FUNCTIONS*/

};

#endif /* CHARACTERSELECTSTATE_H */

