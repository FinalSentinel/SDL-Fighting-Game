/*
 * GameEngine.h
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#ifndef GAMEENGINE_GAMEENGINE_H_
#define GAMEENGINE_GAMEENGINE_H_

#include <fstream>
#include <string>
#include <vector>

#include "SDL.h"
#include "Window.h"

//TODO flags enum?

//Maximum allowed players.
const unsigned int MAX_PLAYERS = 4;

class GameState;
class Player;

class GameEngine {
private:
	//TODO background thread for loading and holding states.
	
    bool quit;
	
    std::vector<Player*> players;

    std::vector<GameState*> stateStack;

    //TODO Add active back in?

protected:

public:
    Window gameWindow;
	
	std::ifstream fileI;
	std::ofstream fileO;
	
	SDL_Event e;
	
	
	
    GameEngine();

    virtual ~GameEngine();



    void addPlayer(Player* p);

    void changeState(GameState* state);

    bool close();

    void eventHandler();

    bool init();
	
	GameState* get_back();

    std::vector<Player*> getPlayersList() const;
	
	bool get_quit();

    void popState();

    void pushState(GameState* state);

    void removePlayer(unsigned int n);

    void render();
	
	void set_quit(bool q);

    void update();
};

#endif /* GAMEENGINE_GAMEENGINE_H_ */


