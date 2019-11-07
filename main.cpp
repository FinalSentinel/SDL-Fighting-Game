/*
 * main.cpp
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

//TODO restrict to 4 players

#include "GameEngine.h"

#include "TitleState.h"

int main(int argc, char* argv[]){
    //TODO Folder structures.
    //TODO XML encoded options files?
    
    GameEngine* game = new GameEngine();

    if(!game->init()){
        std::cerr << "ERROR engine not initialized properly." << std::endl;

        //TODO better init error catching?
        exit(1);
    }
    else{
        game->pushState(new TitleState());

        while(!game->get_quit()){
			game->render();

            game->eventHandler();

            game->update();
        }
    }

    game->close();

    return 0;
}
