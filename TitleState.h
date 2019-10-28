/*
 * TitleState.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef TITLESTATE_H
#define TITLESTATE_H

#include "Texture.h"
#include "GameState.h"

class TitleState: public GameState{
private:
    Texture titleText;
    Texture titleTexture;

protected:
	//NONE

public:
	TitleState(void);

	~TitleState(void);

    void load(void);
	
	std::string name(void) const;

    void pause(void);

    void render(void) const;

    void resume(void);

    void unload(void);

    void update(void);

    //TODO event handler
    void controllerAxisHandler(void);

    void controllerButtonHandler(void);

    void keyHandler(void);

    void windowHandler(void);

};

#endif /* TITLESTATE_H */
