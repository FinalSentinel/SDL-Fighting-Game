/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SFX.h
 * Author: Clayton
 *
 * Created on September 9, 2019, 5:21 PM
 */

#ifndef SFX_H
#define SFX_H

#include "SDL_mixer.h"



class SFX{
private:
	const char* file;
	
	Mix_Chunk* effect;

protected:

public:
	SFX(const char* f = "grunt.ogg");

	virtual ~SFX();
	
	
	
	Mix_Chunk* get_effect();
	
	const char* get_file();
};

#endif /* SFX_H */

