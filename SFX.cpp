/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SFX.cpp
 * Author: Clayton
 * 
 * Created on September 9, 2019, 5:21 PM
 */

#include "SFX.h"

#include <iostream>



SFX::SFX(const char* f): file(f){
    effect = Mix_LoadWAV(file);
    if(effect == nullptr){
        std::cerr << "ERROR unable to load SFX - " << file << ": " << Mix_GetError() << std::endl;
    }
}

SFX::~SFX(){
    if(effect != nullptr){
        Mix_FreeChunk(effect);
        effect = nullptr;
    }
}



Mix_Chunk* SFX::get_effect(){
    return effect;
}

const char* SFX::get_file(){
    return file;
}