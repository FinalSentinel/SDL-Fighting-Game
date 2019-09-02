/*
 * Window.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include <basetsd.h>

#include "Window.h"

#include "SDL.h"

const int Window::totalResNum = 25;
        
const int Window::resolutions[totalResNum][2] = 
            {{ 120,   90}, { 144,  108}, { 240,  180}, { 360,  270}, { 480,  360},
             { 640,  360}, { 640,  480}, { 720,  480}, { 800,  450}, { 800,  600},
             { 960,  540}, { 960,  720}, {1024,  576}, {1024,  768}, {1280,  720},
             {1280,  960}, {1366,  768}, {1600,  900}, {1920,  810}, {1920, 1080},
             {2560, 1080}, {2560, 1440}, {3440, 1440}, {3840, 2160}, {5120, 2160} };
	
const char Window::videoConfig[] = "videoConfig.txt";

const char Window::videoDefault[] = "videoConfigDefault.txt";



Window::Window(int res, bool f, bool v): window(nullptr), renderer(nullptr),
                                         resNum(res), fullscreen(f), vSync(v){
    //NOTHING
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
    //if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetWindowDisplayMode(window, &m);
        
        return m.h;
//    }
//    else{
//        return resolutions[resNum][1];
//    }
}

int Window::getWidth(){
    //if(fullscreen){
        SDL_DisplayMode m;
        SDL_GetWindowDisplayMode(window, &m);
        
        return m.w;
//    }
//    else{
//        return resolutions[resNum][0];
//    }
}

void Window::set_fullscreen(bool f){
    fullscreen = f;
    
    return;
}

void Window::set_resNum(int r){
    resNum = r;
    
    return;
}

void Window::set_vSync(bool v){
    vSync = v;
    
    return;
}

void Window::swapDisplayMode(bool f){
    SDL_SetWindowFullscreen(window, f ? SDL_WINDOW_FULLSCREEN : 0);
    
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    
    return;
}

void Window::swapResolution(int res){
    SDL_SetWindowSize(window, resolutions[res][0], resolutions[res][1]);
    
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    
    return;
}

void Window::swapVSync(bool v){
    SDL_SetHint(SDL_HINT_RENDER_VSYNC, v ? "1" : "0");
    
    return;
}
