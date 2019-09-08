/*
 * Entity.h
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

class Entity {
protected:
    //Position.
    int x, y;
    //Momentum always starts at 0.  Use setters on spawn to have initial momentum.
    int dx = 0, dy = 0;

    bool left;

    //TODO add animation lists

    //TODO add palettes
    int palette;

    //TODO add frame vector

    //TODO add Entity states

public:

    Entity(int x = 0, int y = 0, bool left = true, int p = 0);

    virtual ~Entity();


    virtual bool get_left();

    virtual void set_left(bool l);

    virtual void move(int x, int y) = 0;

    virtual void update() = 0;
};

#endif /* ENTITY_H_ */
