/* 
 * File:   SFX.h
 * Author: Clayton
 *
 * Created on September 9, 2019, 5:21 PM
 */

#ifndef SFX_H
#define SFX_H

#include "SDL_mixer.h"

class SFX{
private:
	const char* file;
	
	Mix_Chunk* effect;

protected:
	//NONE

public:
	SFX(const char* f = "grunt.ogg");

	virtual ~SFX(void);
	
	Mix_Chunk* get_effect(void) const;
	
	const char* get_file(void) const;

};

#endif /* SFX_H */

