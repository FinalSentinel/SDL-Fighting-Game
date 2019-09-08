/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AudioMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "AudioMenu.h"

AudioMenu::AudioMenu(){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Master Volume", new Texture(), std::bind(Master, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Music Volume", new Texture(), std::bind(Music, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Voice Volume", new Texture(), std::bind(Voice, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Effects Volume", new Texture(), std::bind(Effects, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Default", new Texture(), std::bind(Default, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(back, this)));
}

AudioMenu::~AudioMenu(){
}



std::string AudioMenu::name(){
    return "AudioMenu";
}



/*MENU FUNCTIONS*/
void AudioMenu::Master(){


    return;
}

void AudioMenu::Music(){


    return;
}

void AudioMenu::Voice(){


    return;
}

void AudioMenu::Effects(){


    return;
}

void AudioMenu::Default(){


    return;
}