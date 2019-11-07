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
	//NONE

public:
	Song(const char* f = "AEUHHH.mp3", double l = 0);

	virtual ~Song(void);
	
	const char* get_file(void) const;
	
	double get_loop(void) const;
	
	Mix_Music* get_song(void) const;

};

#endif /* SONG_H */