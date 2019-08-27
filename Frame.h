/*
 * Frame.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_ENTITIES_CHARACTERS_FRAME_H_
#define GAMEOBJECTS_ENTITIES_CHARACTERS_FRAME_H_

#include <vector>

class Box;

class Frame {
private:
    std::vector<Box> collisionBoxes;
    std::vector<Box> hitBoxes;
    std::vector<Box> hurtBoxes;

public:
    Frame();
    virtual ~Frame();
    Frame(const Frame& other);
};

#endif /* GAMEOBJECTS_ENTITIES_CHARACTERS_FRAME_H_ */
