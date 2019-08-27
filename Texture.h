/*
 * Texture.h
 *
 *  Created on: Aug 15, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_TEXTURE_H_
#define GAMEOBJECTS_TEXTURE_H_

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"



//Default text
const std::string LOREM = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

class Texture {
private:
    int width, height;

    SDL_Texture* texture;

public:

    Texture() : width(0), height(0), texture(nullptr) {
    };

    virtual ~Texture();



    int get_h();

    int get_w();

    //TODO Composite Image/Text render
    bool loadImage(SDL_Renderer* rend, std::string path = "default.png");

    bool loadText(SDL_Renderer* rend, std::string text = LOREM, int pt = 12, std::string path = "Cirno.ttf", SDL_Color color = {0x00, 0x00, 0x00, 0xFF}, SDL_Color back = {0xFF, 0xFF, 0xFF, 0x80});

    void render(SDL_Renderer* rend, int x = 0, int y = 0, int w = -1, int h = -1, SDL_Rect* clip = nullptr, double angle = 0, SDL_Point* axis = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//TODO modulation stuff
	void setRGBA(Uint8 red = 0xFF, Uint8 green = 0xFF, Uint8 blue = 0xFF, Uint8 alpha = 0xFF);
};

#endif /* GAMEOBJECTS_TEXTURE_H_ */
