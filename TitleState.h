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
    //static TitleState state;

    Texture titleText;
    Texture titleTexture;

protected:

//    TitleState() {
//    };
//
//    virtual ~TitleState() {
//    };

public:
    //static TitleState* instance();



    void load();
	
	std::string name();

    void pause(/*TODO*/);

    void render();

    void resume(/*TODO*/);

    void unload(/*TODO*/);

    void update();



    //TODO event handler
    void controllerAxisHandler(SDL_Event e);

    void controllerButtonHandler(SDL_Event e);

    void keyHandler(SDL_Event e);

    void windowHandler(SDL_Event e);
};

#endif /* GAMEENGINE_STATES_TITLESTATE_H_ */
