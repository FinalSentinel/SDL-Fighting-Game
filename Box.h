/*
 * Box.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Clayton
 */

//Generic display Box class
//TODO should different box type be separate subclasses or all just Box classes?
#ifndef BOX_H_
#define BOX_H_

#include "SDL.h"

class Box {
protected:
    //Universal alphas for when rendering a Box.
    static Uint8 aIn;
    static Uint8 aOut;

    //Anchors box position relative to Entity.
    const int ax, ay;

    SDL_Rect rect;

    SDL_Color color;


public:

    Box(int x = 0, int y = 0, int ax = 0, int ay = 0, int w = 0, int h = 0, SDL_Color color = {0xFF, 0xFF, 0xFF});

    virtual ~Box();

    /* TODO box copy constructor
    Box(const Box& other);
     */

    //collision detection
    bool collide(Box* b) const;

    int get_x() const;

    int get_y() const;

    int get_w() const;

    int get_h() const;

    int get_ax() const;

    int get_ay() const;

    //Set Box XY position
    void move(int x, int y);

    void render(SDL_Renderer* renderer) const;

};

#endif /* BOX_H_ */
