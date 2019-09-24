/*
 * TitleState.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEENGINE_STATES_TITLESTATE_H_
#define GAMEENGINE_STATES_TITLESTATE_H_

#include "Texture.h"
#include "GameState.h"

class TitleState : public GameState{
private:
    Texture titleText;
    Texture titleTexture;

protected:

//    TitleState() {
//    };
//
//    virtual ~TitleState() {
//    };

public:
    void load();
	
	std::string name();

    void pause(/*TODO*/);

    void render();

    void resume(/*TODO*/);

    void unload(/*TODO*/);

    void update();



    //TODO event handler
    void controllerAxisHandler();

    void controllerButtonHandler();

    void keyHandler();

    void windowHandler();
};

#endif /* GAMEENGINE_STATES_TITLESTATE_H_ */
