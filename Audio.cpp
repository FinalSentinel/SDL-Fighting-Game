/* 
 * File:   Audio.cpp
 * Author: Clayton
 * 
 * Created on September 7, 2019, 10:55 PM
 */

#include "Audio.h"

#include <fstream>
#include <iostream>
#include <string>

#include "Song.h"
#include "SFX.h"

const char Audio::audioConfig[] = "audioConfig.txt";



Audio::Audio(int ma, int mu, int vo, int ef): master(ma), music(mu), voice(vo), effects(ef){
    //NONE
}

Audio::~Audio(void){
    //NONE
}

int Audio::get_effects(void) const{
    return effects;
}

int Audio::get_master(void) const{
    return master;
}

int Audio::get_music(void) const{
    return music;
}

int Audio::get_voice(void) const{
    return voice;
}

bool Audio::init(void){
    bool success = false;

	//NOTE audio channel groups?

    //Allocate channels
    if(Mix_AllocateChannels(16) < 16){
        std::cerr << "ERROR allocate channels: " << Mix_GetError() << std::endl;
    }
	else{
		//sets all volume settings 
		set_master(master);

		success = true;
	}
    
    return success;
}

SFX* Audio::loadEffect(const char* file){
    return new SFX(file);
}

Song* Audio::loadSong(const char* file, const double loop){
    return new Song(file, loop);
}

void Audio::play(SFX* sfx, const int loop, const int milli) const{
    Mix_PlayChannelTimed(-1, sfx->get_effect(), loop, milli);
    
    return;
}

void Audio::play(Song* song, const int loop, const int fade, const double position) const{
    Mix_FadeInMusicPos(song->get_song(), loop, fade, position);
    
    //TODO alternate file format loops
    
    return;
}

void Audio::saveSettings(void){
    //TODO
    std::ofstream ofs;

    ofs.open(audioConfig);
    if(!ofs.is_open()){
        std::cerr << "ERROR unable to open audio config file" << std::endl;
    }
    else{
        std::string temp = std::to_string(master) + '\n' +
                           std::to_string(music)  + '\n' +
                           std::to_string(voice)  + '\n' +
                           std::to_string(effects);

        ofs << temp;
    }
    ofs.close();

    return;
}

void Audio::set_effects(const int ef){
    effects = ef;

    for(int i = 3; i < 16; i++){
        Mix_Volume(i, int((master / 100.0) * (effects / 100.0) * MIX_MAX_VOLUME + 0.5));
    }
    
    return;
}

void Audio::set_master(const int ma){
    master = ma;

    set_effects(effects);
    set_music(music);
    set_voice(voice);
    
    return;
}

void Audio::set_music(const int mu){
    music = mu;

    for(int i = 0; i < 3; i++){
        Mix_VolumeMusic(int((master / 100.0) * (music / 100.0) * MIX_MAX_VOLUME + 0.5));
    }
    
    return;
}

void Audio::set_voice(const int vo){
    voice = vo;

    for(int i = 0; i < 3; i++){
        Mix_Volume(i, int((master / 100.0) * (voice / 100.0) * MIX_MAX_VOLUME + 0.5));
    }
    
    return;
}

void Audio::unloadEffect(SFX* sound){
    delete sound;
    sound = nullptr;
    
    return;
}

void Audio::unloadSong(Song* song){
    delete song;
    song = nullptr;
    
    return;
}
