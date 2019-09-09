/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Song.h
 * Author: Clayton
 *
 * Created on September 9, 2019, 3:53 PM
 */

#ifndef SONG_H
#define SONG_H

#include "SDL_mixer.h"



class Song{
private:
	const char* file;
	
	const double loop;
	
	Mix_Music* song;

protected:

public:
	Song(const char f[] = "AEUHHH.mp3", double l = 0);

	virtual ~Song();
	
	
	
	const char* get_file();
	
	double get_loop();
	
	Mix_Music* get_song();

};

#endif /* SONG_H */

