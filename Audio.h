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

class Audio{
private:

protected:
	int master, music, voice, effects;

public:
	static const char audioConfig[];
	
	
	
	Audio(int ma = 80, int mu = 80, int vo = 80, int ef = 80);

	virtual ~Audio();

	
	
	int get_effects();
	
	int get_master();
	
	int get_music();
	
	int get_voice();
	
	void init();
	
	void set_effects(int ma);
	
	void set_master(int ma);
	
	void set_music(int ma);
	
	void set_voice(int ma);
};

#endif /* AUDIO_H */

