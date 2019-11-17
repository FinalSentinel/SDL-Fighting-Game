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
	ARCADE,
	ONLINE,
	TRAINING,
	COMBO,
	TUTORIAL
};

class Character;
struct SDL_Rect;
class Texture;

class VersusState: public GameState{
/*MODE ENUMS*/
public:
	//VERSUS


	//ARCADE


	//ONLINE


	//TRAINING
	enum Training{
		//The positions returned to on Training mode reset.
		RESET_POSITION,
		//Distance the opponent will be on Training mode reset.
		//TODO Hold attack button on reset to set?  Hold attack and tap Reset twice?
		RESET_DISTANCE,
		//Whether to reset with the player on the right.
		RESET_SWAP,
		//Whether directions+reset will change the reset position of Training mode.
		//TODO tap Reset 3 times to toggle.
		RESET_LOCK,
		num_Training
	};
	enum Training_ResetPosition{
		LEFT_WALL,
		LEFT,
		CENTER,
		RIGHT,
		RIGHT_WALL,
		num_Training_ResetPosition
	};
	const std::string resetPositions[num_Training_ResetPosition] = {
		"LEFT WALL",
		"LEFT",
		"CENTER",
		"RIGHT",
		"RIGHT WALL"
	};

	enum Training_ResetDistance{
		CLOSE,
		MEDIUM,
		FAR,
		MAX,
		num_Training_ResetDistance
	};
	const std::string resetDistances[num_Training_ResetDistance] = {
		"CLOSE",
		"MEDIUM",
		"FAR",
		"MAX"
	};

	//COMBO


	//TUTORIAL

private:
	int mode, level, music;

	bool side;

	SDL_Rect* camera;

	Texture* stage;

	Player* active[STAGE_ACTIVE_PLAYERS];

	/*Mode variables*/
	//VERSUS


	//ARCADE


	//ONLINE


	//TRAINING
	static const char* trainingConfig;

	static const char* trainingConfigDefault;

	int trainingSettings[num_Training];

	//COMBO


	//TUTORIAL


protected:
	//NONE

public:
    VersusState(int vMode, int vLevel, int vMusic);

    virtual ~VersusState(void);

    void decollide(Character* c1, Character* c2);

	int get_mode(void) const;

	const char* get_trainingConfig(void) const;

	const char* get_trainingConfigDefault(void) const;

	int get_trainingSettings(int i) const;

    void load(void);
	
	void moveCamera(Character* c);
	
	std::string name(void) const;

    void pause(void);

    void render(void) const;

	void reset(void);

    void resume(void);

	void set_resetDistance(int rD);

	void set_resetLock(int rL);

	void set_resetPosition(int rP);

	void set_resetSwap(int s);

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
