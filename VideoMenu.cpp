/* 
 * File:   VideoMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "VideoMenu.h"

const char VideoMenu::videoDefault[] = "videoConfigDefault.txt";

const std::string VideoMenu::menuText[VideoMenu::numOptions] = {
	"Resolution: ",
	"Fullscreen: ",
	"VSync: ",
	"Default",
	"Back"
};

void(VideoMenu::* const VideoMenu::menuActions[VideoMenu::numOptions])(void) = {
	&VideoMenu::Resolution,
	&VideoMenu::Fullscreen,
	&VideoMenu::VSync,
	&VideoMenu::Default,
	&MenuState::back
};



VideoMenu::VideoMenu(): prompt(false), keep(false), isback(false){
    dials[RESOLUTION_DIAL] =	  game->gameWindow.get_resNum();
    dials[FULLSCREEN_DIAL] = (int)game->gameWindow.get_fullscreen();
    dials[VSYNC_DIAL     ] = (int)game->gameWindow.get_vSync();
    
    resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];
    
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}

	std::get<TEXT>(options[RESOLUTION]).append(std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]));
	std::get<TEXT>(options[FULLSCREEN]).append(std::string(dials[FULLSCREEN_DIAL] ? "ON" : "OFF"));
	std::get<TEXT>(options[VSYNC     ]).append(std::string(dials[VSYNC_DIAL] ? "ON" : "OFF"));



    if(dials[FULLSCREEN_DIAL]){
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
    
    if(dials[FULLSCREEN_DIAL]){
        std::get<TEXTURE>(options[0])->setRGBA(0x80, 0x80, 0x80);
    }
    
    return;
}

std::string VideoMenu::name(void) const{
    return "VideoMenu";
}

void VideoMenu::reload(void){
    std::get<TEXT>(options[0]) = "Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]);
    std::get<TEXT>(options[1]) = "Fullscreen: " + std::string(dials[FULLSCREEN_DIAL] ? "ON" : "OFF");
    std::get<TEXT>(options[2]) = "VSync: " + std::string(dials[VSYNC_DIAL] ? "ON" : "OFF");
    
    for(int i = 0; i < 3; i++){
        std::get<TEXTURE>(options[i])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[i]), 100);
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

                dials[RESOLUTION_DIAL] = game->gameWindow.get_resNum();
                dials[FULLSCREEN_DIAL] = game->gameWindow.get_fullscreen();
                dials[VSYNC_DIAL] = game->gameWindow.get_vSync();

                resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];

                game->gameWindow.swapResolution(dials[RESOLUTION_DIAL]);
                game->gameWindow.swapDisplayMode(dials[FULLSCREEN_DIAL]);
                game->gameWindow.swapVSync(dials[VSYNC_DIAL]);

                if(isback){
                    MenuState::back();
                }
                else{
                    prompt = false;
                
                    reload();

                    for(unsigned int i = 0; i < options.size(); i++){
                        std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                    if(dials[FULLSCREEN_DIAL]){
                        std::get<TEXTURE>(options[0])->setRGBA(0x80, 0x80, 0x80);
                    }
                }
            }
            else if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_A && keep){
                keep = false;

                game->gameWindow.set_resNum(dials[RESOLUTION_DIAL]);
                game->gameWindow.set_fullscreen(dials[FULLSCREEN_DIAL]);
                game->gameWindow.set_vSync(dials[VSYNC_DIAL]);
                
                resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];
                
                //TODO move to Window class
                game->fileO.open(game->gameWindow.videoConfig);
                if(!game->fileO.is_open()){
                    std::cerr<<"ERROR unable to open config file.";
                }
                else{
                    std::string hold = std::to_string(dials[RESOLUTION_DIAL] )+ '\n' +
                                       std::to_string(dials[FULLSCREEN_DIAL]) + '\n' +
                                       std::to_string(dials[VSYNC_DIAL])      + '\n'  ;
                    
                    game->fileO << hold;
                }
                game->fileO.close();

                if(isback){
                    MenuState::back();
                }
                else{
                    prompt = false;

                    for(unsigned int i = 0; i < options.size(); i++){
                        std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
                    if(dials[FULLSCREEN_DIAL]){
                        std::get<TEXTURE>(options[0])->setRGBA(0x80, 0x80, 0x80);
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
                    case RESOLUTION_DIAL:
                    {
                        if(game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT){
                            dials[RESOLUTION_DIAL] = (WINDOW_RESOLUTION_NUM + dials[RESOLUTION_DIAL] - 1) % WINDOW_RESOLUTION_NUM;
                        }
                        else{
                            dials[RESOLUTION_DIAL] = (WINDOW_RESOLUTION_NUM + dials[RESOLUTION_DIAL] + 1) % WINDOW_RESOLUTION_NUM;
                        }
                        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];

                        std::get<TEXT>(options[selection]) = "Resolution: " + std::to_string(resolution[0]) + "x" + std::to_string(resolution[1]);

                        break;
                    }

                    case FULLSCREEN_DIAL:
                    {
                        dials[FULLSCREEN_DIAL] = !dials[FULLSCREEN_DIAL];

                        std::get<TEXT>(options[selection]) = "Fullscreen: " + std::string(dials[FULLSCREEN_DIAL] ? "ON" : "OFF");

                        break;
                    }

                    case VSYNC_DIAL:
                    {
                        dials[VSYNC_DIAL] = !dials[VSYNC_DIAL];

                        std::get<TEXT>(options[selection]) = "VSync: " + std::string(dials[VSYNC_DIAL] ? "ON" : "OFF");

                        break;
                    }

                    default:
                    {
                        std::cerr << "ERROR bad selection" << std::endl;

                        break;
                    }
                }
                std::get<TEXTURE>(options[selection])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[selection]), 100);
                std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
            }
        }
        if(game->gameWindow.get_fullscreen() && (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_UP ||
                game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN)){
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                std::get<TEXTURE>(options[selection])->setRGBA();
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
                std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);

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
    if(!game->gameWindow.get_fullscreen() && dials[RESOLUTION_DIAL] != game->gameWindow.get_resNum()){
        game->gameWindow.swapResolution(dials[RESOLUTION_DIAL]);
    
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    
    return;
}

void VideoMenu::Fullscreen(void){
    //FIXME strange behavior coming out of fullscreen
    if((bool)dials[FULLSCREEN_DIAL] != game->gameWindow.get_fullscreen()){
        game->gameWindow.swapDisplayMode(dials[RESOLUTION_DIAL]);
        
        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];
    
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    
    return;
}

void VideoMenu::VSync(void){
    if((bool)dials[VSYNC_DIAL] != game->gameWindow.get_vSync()){
        game->gameWindow.swapVSync(dials[VSYNC_DIAL]);
        
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);

        for(unsigned int i = 0; i < options.size(); i++){
            std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
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
        game->fileI>>std::dec>>dials[RESOLUTION_DIAL]>>dials[FULLSCREEN_DIAL]>>dials[VSYNC_DIAL];
            
        resolution = WINDOW_RESOLUTION_LIST[dials[RESOLUTION_DIAL]];
        
        reload();
        
        prompt = true;
        
        resPrompt->loadText(game->gameWindow.renderer, "Keep video settings?: " + std::string(keep ? "Yes" : "No"), 100);
        
        for(unsigned int i = 0; i < options.size(); i++){
            std::get<TEXTURE>(options[i])->setRGBA(0xFF, 0xFF, 0xFF, 0x40);
        }
    }
    game->fileI.close();
    
    return;
}

void VideoMenu::back(void){
    if(!game->gameWindow.get_fullscreen() && dials[RESOLUTION_DIAL] != game->gameWindow.get_resNum() ||
            (bool)dials[FULLSCREEN_DIAL] != game->gameWindow.get_fullscreen()                        ||
            (bool)dials[VSYNC_DIAL] != game->gameWindow.get_vSync())                                   {
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
