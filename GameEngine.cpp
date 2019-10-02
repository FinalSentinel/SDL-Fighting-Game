/*
 * GameEngine.cpp
 *
 *  Created on: Aug 12, 2019
 *      Author: Clayton
 */

#include "GameEngine.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "GameState.h"
#include "Player.h"
#include "Window.h"

//XXX
#include "TitleState.h"
#include "MainMenu.h"
#include "MenuState.h"
#include <typeinfo>

GameEngine::GameEngine(): quit(false){
    fileI.open(gameAudio.audioConfig);
    if(!fileI.is_open()){
        std::cerr<<"ERROR unable to open audio config file"<<std::endl;
        exit(2);
    }
    else{        
        int ma, mu, vo, ef;

        fileI >> std::dec >> ma >> mu >> vo >> ef;
                
        gameAudio = Audio(ma, mu, vo, ef);
    }
    fileI.close();
    
    fileI.open(gameWindow.videoConfig);
    if(!fileI.is_open()){
        std::cerr<<"ERROR unable to open video config file"<<std::endl;
        exit(3);
    }
    else{
        int r, f, v;
        
        fileI>>std::dec>>r>>f>>v;
        
        gameWindow = Window(r, f, v);
    }
    fileI.close();
}

GameEngine::~GameEngine(){
    for(int i = 0; i < players.size(); i++){
        delete players[i];
        players.pop_back();
    }
    
    for(int i = 0; i < stateStack.size(); i++){
        delete stateStack[i];
        stateStack.pop_back();
    }
}



void GameEngine::addPlayer(Player* p){
    if(MAX_PLAYERS > 0){
        if(players.size() < MAX_PLAYERS){
            unsigned int i = 0;
            //Holds first found empty slot
            int n = -1;

            //Search for empty players slot
            while(i < players.size() && n == -1){
                //IF empty players slot found.
                if(players[i] == nullptr){
                    //Hold empty players slot index.
                    n = i;
                }

                i++;
            }

            //If empty players slot found.
            if(n != -1){
                players[n] = p;
            }else{
                //Else create new players slot.
                players.emplace_back(p);
            }
        }else{
            std::cerr << "ERROR Maximum players reached" << std::endl;
        }
    }

    return;
}

//TODO check for state already on stack.

void GameEngine::changeState(GameState* state){
    bool found = false;
    //Unload and remove current state
    while(!stateStack.empty() && !found){
        found = (stateStack.back()->name() == state->name());
        if(!found){
            stateStack.back()->unload();
            delete stateStack.back();
            stateStack.pop_back();
        }
    }

    //Store and load new state
    if(!stateStack.empty()){
        stateStack.back()->resume();
    }
    else{
        stateStack.push_back(state);
        stateStack.back()->load();
    }

    return;
}

void GameEngine::close(){
    quit = true;

    while(Mix_Init(0)){
        Mix_Quit();
    }

    IMG_Quit();
    TTF_Quit();
    
    SDL_Quit();

    return;
}

void GameEngine::eventHandler(){
    while(SDL_PollEvent(&e)){
        //Engine handles game-wide events such as adding/removing controllers, or quitting, then pass to game state
        switch(e.type){
            case SDL_CONTROLLERAXISMOTION:
            {
                //L2/R2 support
                if(e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERLEFT || e.caxis.axis == SDL_CONTROLLER_AXIS_TRIGGERRIGHT){
                    //Assume controller does not belong to a player.
                    bool player = false;

                    unsigned int i = 0;

                    //Search players for matching controller
                    while(i < players.size() && !player){
                        if(players[i] != nullptr){
                            //Compare button press controller with player slot controller.
                            player = (SDL_GameControllerFromInstanceID(e.caxis.which) == players[i]->controller);
                        }
                        i++;
                    }

                    //If not already a player.
                    if(!player){
                        addPlayer(new Player(players.size(), SDL_GameControllerFromInstanceID(e.caxis.which)));
                    }
                }

                stateStack.back()->eventHandler();
            }
                break;

            case SDL_CONTROLLERBUTTONDOWN:
            {
                //Assume controller does not belong to a player.
                bool player = false;

                unsigned int i = 0;
                //Find first empty controller slot
                //TODO MENU THIS SHIT
                int n = -1;

                //Search players for matching controller
                while(i < players.size() && !player){
                    if(players[i] != nullptr){
                        //Compare button press controller with player slot controller.
                        player = (SDL_GameControllerFromInstanceID(e.cbutton.which) == players[i]->controller);
                        if(n == -1 && players[i]->controller == nullptr){
                            n = i;
                        }
                    }
                    i++;
                }

                //If not already a player.
                if(!player){
                    //If empty controller slot.
                    if(n != -1){
                        players[n]->controller = SDL_GameControllerFromInstanceID(e.cbutton.which);
                    }else{
                        addPlayer(new Player(players.size(), SDL_GameControllerFromInstanceID(e.cbutton.which)));
                    }
                }

                stateStack.back()->eventHandler();
            }
                break;

            case SDL_CONTROLLERDEVICEADDED:
            {
                //TODO Auto added at program start?  Try remove init controller checks.
                //Check if controller already open.
                if(!SDL_GameControllerGetAttached(SDL_GameControllerFromInstanceID(e.cdevice.which))){
                    //Open controller if not open.
                    SDL_GameControllerOpen(e.cdevice.which);
                }

                stateStack.back()->eventHandler();
            }
                break;

            case SDL_CONTROLLERDEVICEREMOVED:
            {
                //TODO pause game at controller loss if in versus
                SDL_GameControllerClose(SDL_GameControllerFromInstanceID(e.cdevice.which));

                //Assume controller is not found
                bool found = false;

                //Move through controllers vector
                unsigned int i = 0;
                while(i < players.size()){
                    if(players[i] != nullptr){
                        //Compare removed controller to controllers vector
                        found = (SDL_GameControllerFromInstanceID(e.cdevice.which) == players[i]->controller);
                    }
                    i++;
                }
                if(found){
                    if(players[i] != players.back()){
                        //If controller not at the end of controllers vector, empty slot.
                        players[i] = nullptr;
                    }else{
                        //If controller is at the end of controllers vector, remove slot.
                        players.pop_back();
                    }
                }

                stateStack.back()->eventHandler();
            }
                break;

            case SDL_CONTROLLERDEVICEREMAPPED:

                stateStack.back()->eventHandler();

                break;

            case SDL_QUIT:
                close();
                break;

                //All other events handled by game state
            default:
                if(!stateStack.empty()){
                    stateStack.back()->eventHandler();
                }
                break;
        }
    }

    return;
}

GameState* GameEngine::get_back(){
    return stateStack.back();
}

std::vector<Player*> GameEngine::getPlayersList(){
    return players;
}

bool GameEngine::get_quit(){
    return quit;
}

bool GameEngine::init(){
    //Assumes initializing error, sets to true if everything initialized properly.
    bool init = false;

    //TODO put in options menu
    //Set hints
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cerr << "Error initializing SDL: " << SDL_GetError() << std::endl;
    }
    else{
        if(!gameWindow.init()){
            std::cerr << "Error initializing game window." << std::endl;
        }
        else{
            if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
                std::cerr << "Error initializing SDL_image: " << IMG_GetError() << std::endl;
            }
            else{
                //Initialize SDL_mixer
                if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0){
                    std::cerr << "Error initializing SDL_mixer: " << Mix_GetError() << std::endl;
                }
                else{
                    if(!gameAudio.init()){
                        std::cerr << "Error initializing game audio." << std::endl;
                    }
                    else{
                        if(TTF_Init() == -1){
                            std::cerr << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
                        }
                        else{
                            //Init succeeded
                            init = true;

                            GameState::game = this;

                            players.emplace_back(new Player(players.size()));
                            players.emplace_back(new Player(players.size()));
                        }
                    }
                }
            }
        }
    }

    return init;
}

void GameEngine::popState(){
    //Unload and remove current state
    if(!stateStack.empty()){
        stateStack.back()->unload();
        delete stateStack.back();
        stateStack.pop_back();
    }

    //Resume prior state
    if(!stateStack.empty()){
        stateStack.back()->resume();
    }

    return;
}

void GameEngine::pushState(GameState* state){
    //Pause current state
    if(!stateStack.empty()){
        stateStack.back()->pause();
    }

    //Load new state
    if(state != nullptr){
        stateStack.push_back(state);
        stateStack.back()->load();
    }

    return;
}

void GameEngine::removePlayer(unsigned int n){
    //If player slot exists and is not already empty.
    if(players[n] != nullptr && n >= 0 && n < players.size()){
        //If player is last in the vector.
        if(n == players.size() - 1){
            players.pop_back();
        }else{
            //TODO? delete player from slot.
            players[n]->~Player();
            players[n] = nullptr;

            //If players is Player 1 (slot 0)
            if(n == 0){
                unsigned int i = 1;

                //Find first non-empty player
                while(i < players.size()){
                    if(players[i] != nullptr){
                        //Set first active player to be new Player 1.
                        players[0] = players[i];
                        players[i] = nullptr;

                        //If last player in vector is now Player 1.
                        if(i == players.size() - 1){
                            players.pop_back();
                        }
                    }
                }
            }
        }
    }

    return;
}

void GameEngine::render(){
    SDL_SetRenderDrawColor(gameWindow.renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(gameWindow.renderer);

    //TODO indexing vs iterating?
    for(unsigned int i = 0; i < stateStack.size(); i++){
        if(stateStack[i]->get_seen()){
            stateStack[i]->render();
        }
    }

    SDL_RenderPresent(gameWindow.renderer);

    return;
}

void GameEngine::set_quit(bool q){
    quit = q;

    return;
}

void GameEngine::update(){
    if(!stateStack.empty()){
        stateStack.back()->update();
    }

    return;
}


