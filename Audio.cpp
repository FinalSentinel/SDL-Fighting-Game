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



const char Audio::audioConfig[] = "videoConfig.txt";



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

void init(){
    
    
    return;
}

void Audio::set_effects(int ef){
    effects = ef;
    
    return;
}

void Audio::set_master(int ma){
    master = ma;
    
    return;
}

void Audio::set_music(int mu){
    music = mu;
    
    return;
}

void Audio::set_voice(int vo){
    voice = vo;
    
    return;
}