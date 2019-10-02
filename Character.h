/*
 * Character.h
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

//Generic character base
#ifndef ENTITIES_CHARACTER_H_
#define ENTITIES_CHARACTER_H_

#include "Entity.h"

enum CharacterID {
    ERROR_CHARACTER = -1, 
    A,
    B,
    C,
    D,
    E,
    F
};

class Box;
class SDL_Renderer;

class Character: public Entity{
private:
    //TODO character dependent collision boxes
    //Vector holding boxes for character collision
    //TODO move to Frame class
    //TODO change to array of 3 types of Box
    std::vector<Box*> collisionBoxes;

    int charID;

    int health;
    int meter;

    //TODO animation stuff

    //TODO add Entity states

public:

    Character(int id = ERROR_CHARACTER, int x = 0, int y = 0, bool l = true, int p = 0, int hp = 0, int sp = 0);

    virtual ~Character();



    //Adds a box to character's collision vector
    void addColBox(int ax, int ay, int w, int h);

    int get_x();

    int get_y();

    int get_dx();

    int get_dy();
	
	int get_id();

    std::vector<Box*> getColBoxes();

    //Moves character to specified position.
    void move(int nx, int ny);

    //TODO render sprites
    //Renders character's collision boxes
    void render(SDL_Renderer* renderer) const;

    void set_dx(int i);

    void set_dy(int i);

    //Moves character position based on current Entity position and velocity
    void update(void);
};

#endif /* ENTITIES_CHARACTER_H_ */
