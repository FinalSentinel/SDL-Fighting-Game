/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GalleryMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:44 PM
 */

#include "GalleryMenu.h"

GalleryMenu::GalleryMenu(){
    /*
    options.emplace_back("");
    actions.emplace_back(std::bind(, this));
    
    */
    
    options.emplace_back("STORY STUFF");
    actions.emplace_back(std::bind(Hold, this));
    
    options.emplace_back("Back");
    actions.emplace_back(std::bind(Back, this));
}

GalleryMenu::GalleryMenu(const GalleryMenu& orig){
}

GalleryMenu::~GalleryMenu(){
}



std::string GalleryMenu::name(){
    return "GalleryMenu";
}



/*MENU FUNCTIONS*/
	void GalleryMenu::Hold(){
            std::cout<<"TEST HOLD TEST"<<std::endl;
            
            return;
        }
        
	void GalleryMenu::Back(){
            game->popState();
            
            return;
        }