/*
 * Window.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_WINDOW_H_
#define GAMEOBJECTS_WINDOW_H_

#include <iostream>

class SDL_Texture;
class SDL_Renderer;
class SDL_Window;

class Window {
private:
    SDL_Window* window;
	
	int resNum;
	
	bool fullscreen;
	bool vSync;

public:
	static const int totalResNum;
	
	static const int resolutions[][2];
	
	static const char videoConfig[];
	
	
	
    //TODO make private?
    SDL_Renderer* renderer;
	
	

    Window(int res = 14, bool f = false, bool v = false);

    virtual ~Window();
	
	

    bool init();
	
	bool get_fullscreen();
	
	int get_resNum();
	
	bool get_vSync();

    int getHeight();

    int getWidth();
	
	void set_fullscreen(bool f);
	
	void set_resNum(int r);
	
	void set_vSync(bool v);

	void swapDisplayMode(bool f);
	
	void swapResolution(int res);
	
	void swapVSync(bool v);
};

#endif /* GAMEOBJECTS_WINDOW_H_ */
