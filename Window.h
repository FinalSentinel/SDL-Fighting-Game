/*
 * Window.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_WINDOW_H_
#define GAMEOBJECTS_WINDOW_H_

#include <iostream>

class SDL_Texture;
class SDL_Renderer;
class SDL_Window;

class Window {
private:
    //TODO option for different dimensions
    int width, height;

public:
    //TODO make private?
    SDL_Renderer* renderer;
    SDL_Window* window;

    /*
    //XXX ???
    SDL_Texture* texture;
     */

    Window(int w = 720, int h = 480) : width(w), height(h), renderer(nullptr), window(nullptr) {
    };

    virtual ~Window();

    bool init();

    int get_h();

    int get_w();
};

#endif /* GAMEOBJECTS_WINDOW_H_ */
