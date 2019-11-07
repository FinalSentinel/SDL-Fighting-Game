#ifndef GLOBALINFO_H
#define GLOBALINFO_H

#include <algorithm>

class Window;



/*CONSTS*/
//Total number of resolution options
extern constexpr int WINDOW_RESOLUTION_NUM = 25;

//List of selectable window resolutions
extern constexpr int WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM][2] = {
	{ 120,   90}, { 144,  108}, { 240,  180}, { 360,  270}, { 480,  360},
	{ 640,  360}, { 640,  480}, { 720,  480}, { 800,  450}, { 800,  600},
	{ 960,  540}, { 960,  720}, {1024,  576}, {1024,  768}, {1280,  720},
	{1280,  960}, {1366,  768}, {1600,  900}, {1920,  810}, {1920, 1080},
	{2560, 1080}, {2560, 1440}, {3440, 1440}, {3840, 2160}, {5120, 2160}
};

//Max players allowed in an active game instance.
extern constexpr unsigned int STAGE_ACTIVE_PLAYERS = 2;

//Stage size ratio (height/width).
extern constexpr double STAGE_SIZE_RATIO = 9.0 / 16;

//Max Window resolution ratio (height/width).
extern constexpr double WINDOW_MAX_SIZE_RATIO = double(WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][1]) / WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][0];

//Units of stage width/height.
extern constexpr int STAGE_WIDTH = 713318400;
extern constexpr int STAGE_HEIGHT = int(STAGE_WIDTH * STAGE_SIZE_RATIO);

//Unit used to snap positions on stage to absolute points in highest allowed window resolution.
extern constexpr int STAGE_SNAP_UNIT = std::min(STAGE_WIDTH  / WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][0],
												STAGE_HEIGHT / WINDOW_RESOLUTION_LIST[WINDOW_RESOLUTION_NUM - 1][1]);



/*DATA*/
//Ratio of stage size in current window resolution to size in max resolution.
//extern double STAGE_RATIO;

//X,Y point to render the stage at based on current window resolution.
extern int WINDOW_REND_X;
extern int WINDOW_REND_Y;

//Width and height to render the stage at based on current window resolution.
extern int WINDOW_REND_W;
extern int WINDOW_REND_H;

//Unit used to render positions to absolute points in window based on current window resolution.
extern int WINDOW_REND_UNIT;



/*FUNCTIONS*/
//Configures window resolution-dependant globals based on current window resolution.
void configureWindowGlobals(Window* w);

#endif