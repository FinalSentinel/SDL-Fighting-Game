/*
 * Entity.h
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

#include "Box.h"

class Window;

//Entity class containing information on position, boxes, and colors and associated function.
class Entity{
private:
	//NONE

protected:
	//Position.
	int x, y;
	//Momentum.
	int dx, dy;

	bool left;

	//TODO add animation lists

	//TODO add frame vector

	//TODO move to Frame class
	//NOTE make sure stuff doesn't disappear out of scope.
	std::vector<Box> boxes[BoxTypeNum];

	//TODO add palettes
	int palette;

public:
	Entity(int x = 0, int y = 0, int dx = 0, int dy = 0, bool left = true, int p = 0);

	virtual ~Entity();

	//Adds a Box to chosen Box type vector, with relative offset x,y anchored to Entity's position and with width/height w,h.
	virtual void addBox(BoxType type, int rx, int ry, int w, int h);

	int get_x() const;

	int get_y() const;

	int get_dx() const;

	int get_dy() const;

	bool get_left() const;

	virtual std::vector<Box> getBoxes(BoxType type) const;

	//Special case of position function.
	//Runs repeatedly to shift position of Entity based on current momentum TODO: (and time-step).
	//TODO time-step based movement
	virtual void move();

	//Moves Enitity to position x,y and updates boxes accordingly.
	virtual void position(int nx, int ny);

	virtual void render(Window* w, bool side) const;

	void set_dx(int ndx);

	void set_dy(int ndy);

	void set_left(bool l);

};

#endif /* ENTITY_H_ */
