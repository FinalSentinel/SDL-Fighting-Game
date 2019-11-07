/*
 * VersusState.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef VERSUSSTATE_H
#define VERSUSSTATE_H

#include "GameState.h"

enum Versus_Types{
	VERSUS,
	ONLINE,
	TRAINING,
	COMBO,
	TUTORIAL,
	ARCADE,
	Versus_TypesNum
};

class Character;
struct SDL_Rect;
class Texture;

class VersusState: public GameState{
private:
	int mode, level, music;

	bool side;
	
    SDL_Rect* camera;
	
	Texture* stage;

    Player* active[STAGE_ACTIVE_PLAYERS];
	
protected:
	//NONE

public:
    VersusState(int vMode, int vLevel, int vMusic);

    virtual ~VersusState(void);

    void decollide(Character* c1, Character* c2);

	int floorCollision(Character* c) const;

    void load(void);
	
	void moveCamera(Character* c);
	
	std::string name(void) const;

    void pause(void);

    void render(void) const;

    void resume(void);

    void unload(void);

    void update(void);

	int wallDistance(Character* c, bool left) const;

    //TODO event handler
    void controllerAxisHandler(void);

    void controllerButtonHandler(void);

    void keyHandler(void);

    void windowHandler(void);

};

#endif /* VERSUSSTATE_H */
