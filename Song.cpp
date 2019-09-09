/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Song.cpp
 * Author: Clayton
 * 
 * Created on September 9, 2019, 3:53 PM
 */

#include "Song.h"

#include <iostream>

Song::Song(const char* f, double l): file(f), loop(l){
    song = Mix_LoadMUS(file);
    if(song == nullptr){
        std::cerr << "ERROR unable to load song - " << file << ": " << Mix_GetError() << std::endl;
    }
}

Song::~Song(){
    if(song != nullptr){
        Mix_FreeMusic(song);
        song = nullptr;
    }
}



const char* Song::get_file(){
    return file;
}

double Song::get_loop(){
    return loop;
}

Mix_Music* Song::get_song(){
    return song;
}