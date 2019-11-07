/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoMenu.h
 * Author: Clayton
 *
 * Created on August 26, 2019, 11:50 PM
 */

#ifndef VIDEOMENU_H
#define VIDEOMENU_H

#include "MenuState.h"

enum Dials{
	RESOLUTION,
	FULLSCREEN,
	VSYNC,
	numDials
};

class VideoMenu: public MenuState{
private:
	int dials[numDials];
	
	//TODO ???
	const int* resolution;
	
	bool prompt;
	
	bool keep;
	
	bool isback;
	
	Texture* resPrompt;

protected:
	//NONE

public:
	static const char videoDefault[];
	
	
	
	VideoMenu(void);

	virtual ~VideoMenu(void);
	
	void load(void);
	
	std::string name(void) const;
	
	void reload(void);
	
	void render(void) const;
	
	void update(void);
	
	virtual void controllerButtonHandler(void);
	
	/*MENU FUNCTIONS*/
	void Resolution(void);
	void Fullscreen(void);
	void VSync(void);
	void Default(void);
	void back(void);

};

#endif /* VIDEOMENU_H */

