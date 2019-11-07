/* 
 * File:   CharacterSelectState.h
 * Author: Clayton
 *
 * Created on September 14, 2019, 10:38 PM
 */

#ifndef CHARACTERSELECTSTATE_H
#define CHARACTERSELECTSTATE_H

#include "GameState.h"

class CharacterSelectState: public GameState{
private:
	//NONE

protected:
	int mode;

public:
	CharacterSelectState(int vMode);

	virtual ~CharacterSelectState(void);
	
	void load(void);

	std::string name(void) const;
	
	void pause(void);
	
	void render(void) const;
	
	void resume(void);
	
	void unload(void);
	
	void update(void);
	
	void controllerAxisHandler(void);
	
	void controllerButtonHandler(void);

	void keyHandler(void);
	
	void windowHandler(void);

};

#endif /* CHARACTERSELECTSTATE_H */

