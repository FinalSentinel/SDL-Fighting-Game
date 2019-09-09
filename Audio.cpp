/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Audio.cpp
 * Author: Clayton
 * 
 * Created on September 7, 2019, 10:55 PM
 */

#include "Audio.h"

#include <iostream>

#include "Song.h"
#include "SFX.h"



const char Audio::audioConfig[] = "audioConfig.txt";



Audio::Audio(int ma, int mu, int vo, int ef): master(ma), music(mu), voice(vo), effects(ef){
    //NONE
}

Audio::~Audio(){
    //NONE
}



int Audio::get_effects(){
    return effects;
}

int Audio::get_master(){
    return master;
}

int Audio::get_music(){
    return music;
}

int Audio::get_voice(){
    return voice;
}

bool Audio::init(){
    bool success = false;

    //Allocate channels
    if(Mix_AllocateChannels(16) < 16){
        std::cerr << "ERROR allocate channels: " << Mix_GetError() << std::endl;
    }
    else{
        if(Mix_ReserveChannels(16) < 16){
            std::cerr << "ERROR reserving channels: " << Mix_GetError() << std::endl;
        }
        else{
            //Voices group {System, Player 1, Player 2}
            if(Mix_GroupChannels(0, 2, VOICES) < 3){
                std::cerr << "ERROR voices group: " << Mix_GetError() << std::endl;
            }
            else{
                //System SFX group {Menu, }
                if(Mix_GroupChannels(3, 5, SYSTEM_SFX) < 3){
                    std::cerr << "ERROR system sfx group: " << Mix_GetError() << std::endl;
                }
                else{
                    //Player 1 SFX groups {STEPS, ATTACKS, PROJECTILES, HITS, }
                    if(Mix_GroupChannels(6, 10, P1_SFX) < 5){
                        std::cerr << "ERROR p1 sfx group: " << Mix_GetError() << std::endl;
                    }
                    else{
                        //Player 2 SFX groups {STEPS, ATTACKS, PROJECTILES, HITS, }
                        if(Mix_GroupChannels(11, 15, P2_SFX) < 5){
                            std::cerr << "ERROR p2 sfx group: " << Mix_GetError() << std::endl;
                        }
                        else{
                            //sets all volume settings 
                            set_master(master);

                            success = true;
                        }
                    }
                }
            }
        }
    }
    
    return success;
}

SFX* Audio::loadEffect(const char* file){
    return new SFX(file);
}

Song* Audio::loadSong(const char* file, double loop){
    return new Song(file, loop);
}

void Audio::set_effects(int ef){
    effects = ef;
        std::cout << "effect " << master << ":" << (master / 100.0) << " " << effects << ":" << (effects / 100.0) << std::endl;
    
    for(int i = 3; i < 16; i++){
        Mix_Volume(i, (master / 100.0) * (effects / 100.0) * MIX_MAX_VOLUME + 0.5);
    }
    
    return;
}

void Audio::set_master(int ma){
    master = ma;
    
    set_effects(effects);
    set_music(music);
    set_voice(voice);
    
    return;
}

void Audio::set_music(int mu){
    music = mu;
std::cout << "music " << master << ":" << (master / 100.0) << " " << music << ":" << (music / 100.0) << std::endl;
    
    for(int i = 0; i < 3; i++){
        Mix_VolumeMusic((master / 100.0) * (voice / 100.0) * MIX_MAX_VOLUME + 0.5);
    }
    
    return;
}

void Audio::set_voice(int vo){
    voice = vo;
std::cout << "voice " << master << ":" << (master / 100.0) << " " << voice << ":" << (voice / 100.0) << std::endl;
    
    for(int i = 0; i < 3; i++){
        Mix_Volume(i, (master / 100.0) * (voice / 100.0) * MIX_MAX_VOLUME + 0.5);
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