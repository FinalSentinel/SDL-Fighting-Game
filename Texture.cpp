/*
 * Texture.cpp
 *
 *  Created on: Aug 15, 2019
 *      Author: Clayton
 */

#include "Texture.h"

#include <iostream>

#include "SDL_image.h"
#include "SDL_ttf.h"

Texture::Texture(): width(0), height(0), texture(nullptr){
    //NONE
}

Texture::~Texture(void){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

int Texture::get_h(void) const{
    return height;
}

int Texture::get_w(void) const{
    return width;
}

bool Texture::loadImage(SDL_Renderer* rend, const std::string path){
    //Get rid of preexisting texture
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    SDL_Texture* hold = nullptr;

    //Load image at path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        std::cerr << "ERROR unable to load linked image: " << SDL_GetError() << std::endl;

        //Try loading default texture.
        loadedSurface = IMG_Load("default.png");
        if(loadedSurface == nullptr){
            std::cerr << "ERROR unable to load default image: " << SDL_GetError() << std::endl;
        }
    }
    if(loadedSurface != nullptr){
        //Color key image
        //TODO custom color key
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0x00, 0xFF, 0x00));

        //Create texture from surface pixels
        hold = SDL_CreateTextureFromSurface(rend, loadedSurface);
        if(hold == nullptr){
            std::cerr << "ERROR unable to create texture: " << SDL_GetError() << std::endl;
        }else{
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    texture = hold;

    return texture != nullptr;
}

bool Texture::loadText(SDL_Renderer* rend, const std::string text, const int pt, const std::string path, const SDL_Color color, const SDL_Color back){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    TTF_Font* font = TTF_OpenFont(path.c_str(), pt);
    if(font == nullptr){
        std::cerr << "EROOR unable to load linked font: " << TTF_GetError() << std::endl;
        font = TTF_OpenFont("Cirno.ttf", pt);
        if(font == nullptr){
            std::cerr << "ERROR unable to load default font: " << TTF_GetError() << std::endl;
        }
    }

    if(font != nullptr){
        //Render text surface
        SDL_Surface* surface = TTF_RenderText_Shaded(font, text.c_str(), color, back);
        if(surface == nullptr){
            std::cerr << "ERROR unable to create text surface: " << TTF_GetError() << std::endl;
        }else{
            //Create texture from surface pixels
            texture = SDL_CreateTextureFromSurface(rend, surface);
            if(texture == NULL){
                std::cerr << "ERROR unable to create texture: " << SDL_GetError() << std::endl;
            }else{
                //Get image dimensions
                width = surface->w;
                height = surface->h;
            }

            //Get rid of old surface
            SDL_FreeSurface(surface);
        }
    }

    return texture != nullptr;
}

void Texture::render(SDL_Renderer* rend, const int x, const int y, int w, int h, SDL_Rect* clip, const double angle, SDL_Point* axis, const SDL_RendererFlip flip) const{
    //TODO look into fixing up
    if(w < 0){
        w = width;
    }
    if(h < 0){
        h = height;
    }
    //TODO map clip section to relative size automatically
    
    //Render to screen
    if(SDL_RenderCopyEx(rend, texture, clip, new SDL_Rect({x, y, w, h}), angle, axis, flip)){
        std::cerr << "ERROR incorrect rendering: " << SDL_GetError() <<std::endl;
    }

    return;
}

void Texture::setBlendMode(const SDL_BlendMode mode){
	//Set blending function
	SDL_SetTextureBlendMode(texture, mode);
}

void Texture::setRGBA(const Uint8 red, const Uint8 green, const Uint8 blue, const Uint8 alpha){
        //Modulate texture rgba
        SDL_SetTextureColorMod(texture, red, green, blue);
        SDL_SetTextureAlphaMod(texture, alpha);

		return;
}
