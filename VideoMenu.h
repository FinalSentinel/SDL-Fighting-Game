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
	//TODO pass enum size
	int dials[numDials];
	
	const int* resolution;
	
	bool prompt;
	
	bool keep;
	
	bool isback;
	
	Texture* resPrompt;

protected:

public:
	VideoMenu();

	virtual ~VideoMenu();
	
	

	void load();
	
	std::string name();
	
	void reload();
	
	void render();
	
	void update();
	
	
	
	virtual void controllerButtonHandler();
	
	
	
	/*MENU FUNCTIONS*/
	void Resolution();
	void Fullscreen();
	void VSync();
	void Default();
	void back();
};

#endif /* VIDEOMENU_H */

