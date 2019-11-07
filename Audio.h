/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Audio.h
 * Author: Clayton
 *
 * Created on September 7, 2019, 10:55 PM
 */

#ifndef AUDIO_H
#define AUDIO_H

#include "SDL_mixer.h"



class Song;
class SFX;

class Audio{
private:
	int master, music, voice, effects;

protected:
	//NONE

public:
	static const char audioConfig[];
	
	
	
	Audio(int ma = 80, int mu = 80, int vo = 80, int ef = 80);

	virtual ~Audio();
	
	int get_effects() const;
	
	int get_master() const;
	
	int get_music() const;
	
	int get_voice() const;
	
	bool init();
	
	SFX* loadEffect(const char* file);
	
	Song* loadSong(const char* file, double loop = 0);
	
	void play(SFX* sfx, int loop = 0, int milli = 0) const;
	
	void play(Song* song, int loop = -1, int fade = 0, double position = 0.0) const;
	
	//TODO Song loop function here, or in Song class?
	
	void saveSettings();
	
	void set_effects(int ma);
	
	void set_master(int ma);
	
	void set_music(int ma);
	
	void set_voice(int ma);
	
	void unloadEffect(SFX* sound);
	
	void unloadSong(Song* song);

};

#endif /* AUDIO_H */

