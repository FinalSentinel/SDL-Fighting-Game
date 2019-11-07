/* 
 * File:   VideoMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "VideoMenu.h"

const char VideoMenu::videoDefault[] = "videoConfigDefault.txt";



VideoMenu::VideoMenu(): prompt(false), keep(false), isback(false){
    dials[RESOLUTION] = game->gameWindow.get_resNum();
    dials[FULLSCREEN] = (int)game->gameWindow.get_fullscreen();
    dials[VSYNC] = (int)game->gameWindow.get_vSync();
    
    resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];
    
    /*
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("", new Texture(), std::bind(&, this)));
    
    */
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]), new Texture(), std::bind(&VideoMenu::Resolution, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Fullscreen: " + std::string(dials[FULLSCREEN] ? "ON" : "OFF"), new Texture(), std::bind(&VideoMenu::Fullscreen, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("VSync: " + std::string(dials[VSYNC] ? "ON" : "OFF"), new Texture(), std::bind(&VideoMenu::VSync, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Default", new Texture(), std::bind(&VideoMenu::Default, this)));
    
    options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
    ("Back", new Texture(), std::bind(&MenuState::back, this)));
    
    if(dials[FULLSCREEN]){
        selection = 1;
        index = 1;
    }
    
    resPrompt = new Texture();
}

VideoMenu::~VideoMenu(void){
    //NONE
}

void VideoMenu::load(void){
    MenuState::load();
    
    if(dials[FULLSCREEN]){
        std::get<GRAPHIC>(options[0])->setRGBA(0x80, 0x80, 0x80);
    }
    
    return;
}

std::string VideoMenu::name(void) const{
    return "VideoMenu";
}

void VideoMenu::reload(void){
    std::get<TEXT>(options[0]) = "Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]);
    std::get<TEXT>(options[1]) = "Fullscreen: " + std::string(dials[FULLSCREEN] ? "ON" : "OFF");
    std::get<TEXT>(options[2]) = "VSync: " + std::string(dials[VSYNC] ? "ON" : "OFF");
    
    for(int i = 0; i < 3; i++){
        std::get<GRAPHIC>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
    }
    
    return;
}

void VideoMenu::render(void) const{
    MenuState::render();
    
    if(prompt){
        //Menu x position is always at 3/5 of window width.
        int x = game->gameWindow.getWidth() / 5;
        //Menu height is the number of window height divided by numOptions + 2,
        //therefore equal blank space above and below.  Will implement scrolling.
        int y = game->gameWindow.getHeight() / 3;

        resPrompt->render(game->gameWindow.renderer, x, y, x * 3, y);
    }
    
    return;
}

void VideoMenu::update(void){
    
    return;
}

void VideoMenu::controllerButtonHandler(void){
    if(prompt){
        if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
            if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP ||
               game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN ||
               game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT ||
               game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT){
                keep = !keep;
                resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);
            }
            else if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_B ||
                    game->e.cbutton.button == SDL_CONTROLLER_BUTTON_A && !keep){
                keep = false;

                dials[RESOLUTION] = game->gameWindow.get_resNum();
                dials[FULLSCREEN] = game->gameWindow.get_fullscreen();
                dials[VSYNC] = game->gameWindow.get_vSync();

                resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];

                game->gameWindow.swapResolution(dials[RESOLUTION]);
                game->gameWindow.swapDisplayMode(dials[FULLSCREEN]);
                game->gameWindow.swapVSync(dials[VSYNC]);

                if(isback){
                    MenuState::back();
                }
                else{
                    prompt = false;
                
                    reload();

                    for(unsigned int i = 0; i < options.size(); i++){
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                    if(dials[FULLSCREEN]){
                        std::get<GRAPHIC>(options[0])->setRGBA(0x80, 0x80, 0x80);
                    }
                }
            }
            else if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_A && keep){
                keep = false;

                game->gameWindow.set_resNum(dials[RESOLUTION]);
                game->gameWindow.set_fullscreen(dials[FULLSCREEN]);
                game->gameWindow.set_vSync(dials[VSYNC]);
                
                resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];
                
                //TODO move to Window class
                game->fileO.open(game->gameWindow.videoConfig);
                if(!game->fileO.is_open()){
                    std::cerr<<"ERROR unable to open config file.";
                }
                else{
                    std::string hold = std::to_string(dials[RESOLUTION] )+ '\n' +
                                       std::to_string(dials[FULLSCREEN]) + '\n' +
                                       std::to_string(dials[VSYNC])      + '\n'  ;
                    
                    game->fileO << hold;
                }
                game->fileO.close();

                if(isback){
                    MenuState::back();
                }
                else{
                    prompt = false;

                    for(unsigned int i = 0; i < options.size(); i++){
                        std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                    if(dials[FULLSCREEN]){
                        std::get<GRAPHIC>(options[0])->setRGBA(0x80, 0x80, 0x80);
                    }
                }
            }
            else if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_START){
                //NOTHING
            }
            else{
                MenuState::controllerButtonHandler();
            }
        }
        else{
            MenuState::controllerButtonHandler();
        }
    }
    else{
        if(selection < 3 && (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT ||
                game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)){
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                switch(selection){
                    case RESOLUTION:
                    {
                        if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT){
                            dials[RESOLUTION] = (WINDOW_RESOLUTION_NUM + dials[RESOLUTION] - 1) % WINDOW_RESOLUTION_NUM;
                        }
                        else{
                            dials[RESOLUTION] = (WINDOW_RESOLUTION_NUM + dials[RESOLUTION] + 1) % WINDOW_RESOLUTION_NUM;
                        }
                        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];

                        std::get<TEXT>(options[selection]) = "Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]);

                        break;
                    }

                    case FULLSCREEN:
                    {
                        dials[FULLSCREEN] = !dials[FULLSCREEN];

                        std::get<TEXT>(options[selection]) = "Fullscreen: " + std::string(dials[FULLSCREEN] ? "ON" : "OFF");

                        break;
                    }

                    case VSYNC:
                    {
                        dials[VSYNC] = !dials[VSYNC];

                        std::get<TEXT>(options[selection]) = "VSync: " + std::string(dials[VSYNC] ? "ON" : "OFF");

                        break;
                    }

                    default:
                    {
                        std::cerr << "ERROR bad selection" << std::endl;

                        break;
                    }
                }
                std::get<GRAPHIC>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);
                std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
            }
        }
        if(game->gameWindow.get_fullscreen() && (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP ||
                game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)){
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                std::get<GRAPHIC>(options[selection])->setRGBA();
                if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP){
                    if(index > 1){
                        index--;
                    }
                    else if(selection == 1){
                        index = std::min((int) options.size() - 1, MAX_MENU_SIZE - 1);
                    }

                    selection = ((options.size() + selection - 3) % (options.size() - 1)) + 1;
                }
                else{
                    if(index < MAX_MENU_SIZE - 1 && index < options.size() - 1){
                        index++;
                    }
                    else if(selection == options.size() - 1){
                        index = 1;
                    }

                    selection = ((options.size() + selection - 1) % (options.size() - 1)) + 1;
                }
                std::get<GRAPHIC>(options[selection])->setRGBA(0xFF, 0x80, 0x00);

            }
        }
        else{
            MenuState::controllerButtonHandler();
        }
    }
    
    return;
}

/*MENU FUNCTIONS*/
void VideoMenu::Resolution(void){
    if(!game->gameWindow.get_fullscreen() && dials[RESOLUTION] != game->gameWindow.get_resNum()){
        game->gameWindow.swapResolution(dials[RESOLUTION]);
    
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    
    return;
}

void VideoMenu::Fullscreen(void){
    //FIXME strange behavior coming out of fullscreen
    if((bool)dials[FULLSCREEN] != game->gameWindow.get_fullscreen()){
        game->gameWindow.swapDisplayMode(dials[RESOLUTION]);
        
        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];
    
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    
    return;
}

void VideoMenu::VSync(void){
    if((bool)dials[VSYNC] != game->gameWindow.get_vSync()){
        game->gameWindow.swapVSync(dials[VSYNC]);
        
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    
    return;
}

void VideoMenu::Default(void){
    game->fileI.open(videoDefault);
    if(!game->fileI.is_open()){
        std::cerr<<"ERROR unable to open video default file"<<std::endl;
    }
    else{
        game->fileI>>std::dec>>dials[RESOLUTION]>>dials[FULLSCREEN]>>dials[VSYNC];
            
        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION]];
        
        reload();
        
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);
        
        for(unsigned int i = 0; i < options.size(); i++){
            std::get<GRAPHIC>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    game->fileI.close();
    
    return;
}

void VideoMenu::back(void){
    if(!game->gameWindow.get_fullscreen() && dials[RESOLUTION] != game->gameWindow.get_resNum() ||
            (bool)dials[FULLSCREEN] != game->gameWindow.get_fullscreen()                        ||
            (bool)dials[VSYNC] != game->gameWindow.get_vSync())                                   {
        Resolution();
        Fullscreen();
        VSync();

        isback = true;
    }
    else{
        MenuState::back();
    }

    return;
}
