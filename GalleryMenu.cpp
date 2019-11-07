/* 
 * File:   GalleryMenu.cpp
 * Author: Clayton
 * 
 * Created on August 25, 2019, 11:44 PM
 */

#include "GalleryMenu.h"

GalleryMenu::GalleryMenu(void){
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
     */

    options.emplace_back(std::tuple < std::string, Texture*, std::function<void()> >
            ("STORY STUFF", new Texture(), std::bind(&GalleryMenu::Hold, this)));

    options.emplace_back(std::tuple < std::string, Texture*, std::function<void()> >
            ("Back", new Texture(), std::bind(&MenuState::back, this)));
}

GalleryMenu::~GalleryMenu(void){
}

std::string GalleryMenu::name(void) const{
    return "GalleryMenu";
}

/*MENU FUNCTIONS*/
void GalleryMenu::Hold(void) const{
    std::cout << "TEST HOLD TEST" << std::endl;

    return;
}
