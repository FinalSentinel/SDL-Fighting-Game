/*
 * Window.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include "Window.h"

#include "GlobalInfo.h"

//XXX ?
#include <basetsd.h>

#include "SDL.h"
	
const char Window::videoConfig[] = "videoConfig.txt";



Window::Window(const int res, const bool f, const bool v):
				window(nullptr), renderer(nullptr), resNum(res), fullscreen(f), vSync(v){
    //NONE
}

Window::~Window(void){
    if(renderer != nullptr){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if(window != nullptr){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

bool Window::init(void){
    bool init = false;

    //TODO load flags from user chosen settings
    window = SDL_CreateWindow("Fighting Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            WINDOW_RESOLUTION_LIST[resNum][0], WINDOW_RESOLUTION_LIST[resNum][1],
            SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);

	configureWindowGlobals(this);

    if(window == nullptr){
        std::cerr << "Error creating window" << std::endl;
    }
	else{
        //TODO user defined VSync
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(renderer == nullptr){
            std::cerr << "Error creating renderer" << std::endl;
        }else{
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

            init = true;
        }
    }

    return init;
}

bool Window::get_fullscreen(void) const{
    return fullscreen;
}

int Window::get_resNum(void) const{
    return resNum;
}

bool Window::get_vSync(void) const{
    return vSync;
}

int Window::getHeight(void) const{
    //if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetWindowDisplayMode(window, &m);
        
        return m.h;
//    }
//    else{
//        return WINDOW_RESOLUTION_LIST[resNum][1];
//    }
}

int Window::getWidth(void) const{
    //if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetWindowDisplayMode(window, &m);
        
        return m.w;
//    }
//    else{
//        return WINDOW_RESOLUTION_LIST[resNum][0];
//    }
}

void Window::set_fullscreen(const bool f){
    fullscreen = f;
    
    return;
}

void Window::set_resNum(const int r){
    resNum = r;
    
    return;
}

void Window::set_vSync(const bool v){
    vSync = v;
    
    return;
}

void Window::swapDisplayMode(const bool f){
    SDL_SetWindowFullscreen(window, f ? SDL_WINDOW_FULLSCREEN : 0);
    
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	configureWindowGlobals(this);
    
    return;
}

void Window::swapResolution(const int res){
    SDL_SetWindowSize(window, WINDOW_RESOLUTION_LIST[res][0], WINDOW_RESOLUTION_LIST[res][1]);
    
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

	configureWindowGlobals(this);
    
    return;
}

void Window::swapVSync(const bool v){
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, v ? "1" : "0");
    
    return;
}
