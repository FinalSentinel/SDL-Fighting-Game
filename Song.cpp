/* 
 * File:   Song.cpp
 * Author: Clayton
 * 
 * Created on September 9, 2019, 3:53 PM
 */

#include "Song.h"

#include <iostream>

Song::Song(const char* f, const double l): file(f), loop(l){
    song = Mix_LoadMUS(file);

    if(song == nullptr){
        std::cerr << "ERROR unable to load song - " << file << ": " << Mix_GetError() << std::endl;
    }
}

Song::~Song(void){
    if(song != nullptr){
        Mix_FreeMusic(song);
        song = nullptr;
    }
}

const char* Song::get_file(void) const{
    return file;
}

double Song::get_loop(void) const{
    return loop;
}

Mix_Music* Song::get_song(void) const{
    return song;
}
