/*
 * Window.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include "Window.h"

#include "SDL.h"

Window::Window(): window(nullptr), renderer(nullptr){
    //TODO Load resNum/fullscreen/vsync from settings file
    resNum = 14;
    fullscreen = false;
    vSync = false;
}

Window::~Window(){
    if(renderer != nullptr){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if(window != nullptr){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}

bool Window::init(){
    bool init = false;

    //TODO load flags from user chosen settings
    window = SDL_CreateWindow("Fighting Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            resolutions[resNum][0], resolutions[resNum][1],
            SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_SHOWN);
    if(window == nullptr){
        std::cerr << "Error creating window" << std::endl;
    }else{
        //TODO user defined VSync
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(renderer == nullptr){
            std::cerr << "Error creating renderer" << std::endl;
        }else{
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

            init = true;

            /*
            //XXX test code
            texture = SDL_CreateTextureFromSurface(renderer, SDL_GetWindowSurface(window));
             */
        }
    }

    return init;
}

bool Window::get_fullscreen(){
    return fullscreen;
}

int Window::get_resNum(){
    return resNum;
}

bool Window::get_vSync(){
    return vSync;
}

int Window::getHeight(){
    if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetCurrentDisplayMode(0, &m);
        
        return m.h;
    }
    else{
        return resolutions[resNum][1];
    }
}

const int* Window::getResolution(int i) const{
    return resolutions[i];
}

int Window::getWidth(){
    if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetCurrentDisplayMode(0, &m);
        
        return m.w;
    }
    else{
        return resolutions[resNum][0];
    }
}

void Window::swapDisplayMode(){
    fullscreen = !fullscreen;
    
    SDL_SetWindowFullscreen(window, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
    
    return;
}

void Window::swapResolution(int res){
    resNum = res;
    
    SDL_SetWindowSize(window, resolutions[res][0], resolutions[res][1]);
    
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    
    return;
}

void Window::swapVSync(){
    vSync = !vSync;

    SDL_SetHint(SDL_HINT_RENDER_VSYNC, (vSync ? "1" : "0"));
    
    return;
}
