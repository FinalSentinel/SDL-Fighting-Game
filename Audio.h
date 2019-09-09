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



enum AUDIO_GROUPS{
	VOICES,
	SYSTEM_SFX,
	P1_SFX,
	P2_SFX,
	audio_groups_num
};

enum VOICES_SLOTS{
	SYSTEM_VOICE = 0,
	P1_VOICE,
	P2_VOICE = 2
};

enum SYSTEM_SFX_SLOTS{
	MENU_SFX = 3,
	placeholder_system_sfx0,
	placeholder_system_sfx1 = 5
};

enum PLAYER_SFX_SLOTS{
	STEP_SFX = 6,
	ATTACK_SFX,
	PROJECTILE_SFX,
	HIT_SFX,
	placeholder_player_sfx0 = 10
};



class Song;
class SFX;

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
	
	bool init();
	
	SFX* loadEffect(const char* file);
	
	Song* loadSong(const char* file, double loop = 0);
	
	//TODO Song/SFX play functions
	
	//TODO Song loop function here, or in Song class?
	
	void set_effects(int ma);
	
	void set_master(int ma);
	
	void set_music(int ma);
	
	void set_voice(int ma);
	
	void unloadEffect(SFX* sound);
	
	void unloadSong(Song* song);
};

#endif /* AUDIO_H */

