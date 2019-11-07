#include "GlobalInfo.h"

#include "Window.h"



/*DATA*/
int WINDOW_REND_X = 0;
int WINDOW_REND_Y = 0;

int WINDOW_REND_W = 0;
int WINDOW_REND_H = 0;

int WINDOW_REND_UNIT = 0;



/*FUNCTIONS*/
void configureWindowGlobals(Window* w){
	if((w->getWidth() * STAGE_SIZE_RATIO) < w->getHeight()){
		WINDOW_REND_W = w->getWidth();
		WINDOW_REND_H = int(w->getWidth() * STAGE_SIZE_RATIO);

		WINDOW_REND_X = 0;
		WINDOW_REND_Y = (w->getHeight() - WINDOW_REND_H) / 2;
	}
	else{
		WINDOW_REND_W = int(w->getHeight() / STAGE_SIZE_RATIO);
		WINDOW_REND_H = w->getHeight();

		WINDOW_REND_X = (w->getWidth() - WINDOW_REND_W) / 2;
		WINDOW_REND_Y = 0;
	}

	WINDOW_REND_UNIT = STAGE_WIDTH  / (w->getWidth() - 2 * WINDOW_REND_X);

	/*
	STAGE_RATIO = std::max((w->getWidth  - 2 * WINDOW_REND_X) / WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][0],
						   (w->getHeight - 2 * WINDOW_REND_Y) / WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][1]);
	*/

	return;
}