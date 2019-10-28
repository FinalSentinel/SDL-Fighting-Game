/*
 * Window.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Window;

class Window{
private:
    SDL_Window* window;
	
	int resNum;
	
	bool fullscreen;

	bool vSync;

protected:
	//NONE

public:
	static const int totalResNum;
	
	//2 resolution values (width, height).
	static const int resolutions[][2];
	
	static const char videoConfig[];
	
    //TODO make private?
    SDL_Renderer* renderer;



    Window(int res = 14, bool f = false, bool v = false);

    virtual ~Window();

    bool init();
	
	bool get_fullscreen() const;
	
	int get_resNum() const;
	
	bool get_vSync() const;

    int getHeight() const;

    int getWidth() const;
	
	void set_fullscreen(bool f);
	
	void set_resNum(int r);
	
	void set_vSync(bool v);

	void swapDisplayMode(bool f);
	
	void swapResolution(int res);
	
	void swapVSync(bool v);

};

#endif /* WINDOW_H */
