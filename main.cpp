/*
 * main.cpp
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#include "GameEngine.h"

#include "TitleState.h"

int main(int argc, char* argv[]){
    //TODO Folder structures.
    //TODO XML encoded options files?
    
    GameEngine* game = new GameEngine();

    if(!game->init()){
        std::cerr << "ERROR engine not initialized properly." << std::endl;
        //TODO better init error catching?
        return 1;
    }
    else{
        game->pushState(new TitleState());

        while(!game->get_quit()){
            game->render();
            game->eventHandler();
            game->update();
        }
    }

    if(!game->close()){
        std::cerr << "ERROR engine not closed properly." << std::endl;
        //TODO better close error catching?
        return -1;
    }

    return 0;
}
