/*
 * Character.h
 *
 *  Created on: Aug 9, 2019
 *      Author: Clayton
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

enum CharacterID {
    ERROR_CHARACTER = -1, 
    CHARACTER_1,
	CHARACTER_2,
	CHARACTER_3,
	CHARACTER_4,
	CHARACTER_5,
	LAMEDH,
	CharacterIDNum
};

class Character: public Entity{
private:
    //TODO character dependent collision boxes
    //Vector holding boxes for character collision

    CharacterID charID;

    int health;

    int meter;

	bool wall;

    //TODO animation stuff

    //TODO add Entity states

protected:
	//NONE

public:
    Character(CharacterID id = ERROR_CHARACTER, int x = 0, int y = 0, bool l = true, int p = 0, int hp = 0, int sp = 0);

    virtual ~Character();
	
	CharacterID get_id() const;

	bool get_wall(void) const;

	void handleEvent(SDL_Event* e);

	void set_wall(bool w);

};

#endif /* CHARACTER_H */
