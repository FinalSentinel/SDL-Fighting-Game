/*
 * Window.h
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#ifndef GAMEOBJECTS_WINDOW_H_
#define GAMEOBJECTS_WINDOW_H_

#include <iostream>

const int resolutions[25][2] = {{ 120,   90}, { 144,  108}, { 240,  180}, { 360,  270}, { 480,  360},
<<<<<<< Upstream, based on origin/master
							    { 640,  360}, { 640,  480}, { 800,  450}, { 800,  600}, { 960,  540},
							    { 960,  720}, {1024,  576}, {1024,  768}, {1280,  720}, {1280,  960},
                                {1366,  768}, {1600,  900}, {1920, 1080}, {1920,  810}, {2560, 1080},
                                {2560, 1440}, {3440, 1440}, {3840, 2160}, {5120, 2160}, {5120, 2160} };
=======
								{ 640,  360}, { 640,  480}, { 720,  480}, { 800,  450}, { 800,  600},
								{ 960,  540}, { 960,  720}, {1024,  576}, {1024,  768}, {1280,  720},
								{1280,  960}, {1366,  768}, {1600,  900}, {1920,  810}, {1920, 1080},
								{2560, 1080}, {2560, 1440}, {3440, 1440}, {3840, 2160}, {5120, 2160} };
>>>>>>> 9932bf5 Video options sans default implemented

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
    //TODO make private?
    SDL_Renderer* renderer;
	
	const int totalResNum = 25;
	
	

    Window();

    virtual ~Window();

    bool init();
	
	bool get_fullscreen();
	
	int get_resNum();
	
	bool get_vSync();

    int getHeight();
<<<<<<< Upstream, based on origin/master
=======
	
	const int* getResolution(int i) const;
>>>>>>> 9932bf5 Video options sans default implemented

    int getWidth();
	
<<<<<<< Upstream, based on origin/master
	void resize(int res);
	
	void swapDisplayMode();
=======
	void swapDisplayMode();
	
	void swapResolution(int res);
>>>>>>> 9932bf5 Video options sans default implemented
	
	void swapVSync();
};

#endif /* GAMEOBJECTS_WINDOW_H_ */
