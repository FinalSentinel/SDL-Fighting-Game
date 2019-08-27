/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VideoMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "VideoMenu.h"

VideoMenu::VideoMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

VideoMenu::VideoMenu(const VideoMenu& orig){
}

VideoMenu::~VideoMenu(){
}



std::string VideoMenu::name(){
    return "VideoMenu";
}



/*MENU FUNCTIONS*/
void VideoMenu::Back(){
    std::cout<<"Options"<<std::endl;
    game->popState();

    return;
}