/*
 * Box.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Clayton
 */

//Generic display Box class
//TODO should different box type be separate subclasses or all just Box classes?
#ifndef BOX_H
#define BOX_H

//TODO remove?
#include "SDL.h"

enum BoxType{
	COLLISION,
	HURT,
	HIT,
	num_BoxType
};

class Box{
private:
	//Universal alphas for when rendering a Box.
	static int aIn;
	static int aOut;

	//Point of Entity relative to anchor.
	const int rx, ry;

	//TODO variable for relative position of box?

	//Absolute position and width/height of box
	SDL_Rect rect;

	SDL_Color color;

protected:
	//NONE

public:
	//TODO change anchor to pointer to Entity to get anchor values directly?
	Box(int ax = 0, int ay = 0, int rx = 0, int ry = 0, int w = 0, int h = 0, SDL_Color color = {0xFF, 0xFF, 0xFF});

	virtual ~Box();

	bool collides(Box b) const;

	//Returns relative x position to anchor.
	int get_rx() const;

	//Returns relative y position to anchor.
	int get_ry() const;

	//Returns absolute x position.
	int get_x() const;

	//Returns absolute y position.
	int get_y() const;

	int get_w() const;

	int get_h() const;

	//Moves the box to nx,ny position offset to anchor point.
	void position(int nx, int ny);

	void render(SDL_Renderer* rend) const;

};

#endif /* BOX_H */
