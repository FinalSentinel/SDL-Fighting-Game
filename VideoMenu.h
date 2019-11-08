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



class VideoMenu: public MenuState{
private:
	enum Dials{
		RESOLUTION_DIAL,
		FULLSCREEN_DIAL,
		VSYNC_DIAL,
		numDials
	};

	static const char videoDefault[];

	static const std::string menuText[];

	//TODO lambdas?
	static void(VideoMenu::* const menuActions[])(void);

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
	enum Video_Options{
		RESOLUTION,
		FULLSCREEN,
		VSYNC,
		DEFAULT,
		BACK,
		numOptions
	};
	
	
	
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

