/* 
 * File:   AudioMenu.cpp
 * Author: Clayton
 * 
 * Created on August 26, 2019, 11:50 PM
 */

#include "AudioMenu.h"
#include "SFX.h"

const char AudioMenu::audioDefault[] = "audioConfigDefault.txt";

const std::string AudioMenu::menuText[AudioMenu::numOptions] = {
	"Master Volume: ",
	"Music Volume: ",
	"Voice Volume: ",
	"Effects Volume: ",
	"Default",
	"Back"
};

void(AudioMenu::* const AudioMenu::menuActions[AudioMenu::numOptions])(void) = {
	&AudioMenu::Master,
	&AudioMenu::Music,
	&AudioMenu::Voices,
	&AudioMenu::Effects,
	&AudioMenu::Default,
	&MenuState::back
};



AudioMenu::AudioMenu(void){
	for(int i = 0; i < numOptions; i++){
		options.emplace_back(std::tuple<std::string, Texture*, std::function<void()> >
			(menuText[i], new Texture(), std::bind(menuActions[i], this)));
	}
	std::get<TEXT>(options[MASTER] ).append(std::to_string(game->gameAudio.get_master()	));
	std::get<TEXT>(options[MUSIC]  ).append(std::to_string(game->gameAudio.get_music()	));
	std::get<TEXT>(options[VOICES] ).append(std::to_string(game->gameAudio.get_voices()	));
	std::get<TEXT>(options[EFFECTS]).append(std::to_string(game->gameAudio.get_effects()));
}

AudioMenu::~AudioMenu(void){
}

std::string AudioMenu::name(void) const{
    return "AudioMenu";
}

void AudioMenu::reload(void){
    std::get<TEXT>(options[0]) = "Master Volume: " + std::to_string(game->gameAudio.get_master());
    std::get<TEXTURE>(options[0])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[0]), 100);
    
    std::get<TEXT>(options[1]) = "Music Volume: " + std::to_string(game->gameAudio.get_music());
    std::get<TEXTURE>(options[1])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[1]), 100);
    
    std::get<TEXT>(options[2]) = "Voice Volume: " + std::to_string(game->gameAudio.get_voices());
    std::get<TEXTURE>(options[2])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[2]), 100);
    
    std::get<TEXT>(options[3]) = "Effects Volume: " + std::to_string(game->gameAudio.get_effects());
    std::get<TEXTURE>(options[3])->loadText(game->gameWindow.renderer, std::get<TEXT>(options[3]), 100);
    
    std::get<TEXTURE>(options[selection])->setRGBA(0xFF, 0x80, 0x00);
        
    return;
}

void AudioMenu::controllerButtonHandler(void){
    if(selection < 4 && game->e.button.type == SDL_CONTROLLERBUTTONDOWN &&
       (game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT       ||
        game->e.cbutton.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT)       ){
        
        callAction();
        
    }
    else{
        MenuState::controllerButtonHandler();
    }
    
    return;
}

/*MENU FUNCTIONS*/
void AudioMenu::Master(void){
    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            if(game->gameAudio.get_master() > 0){
                game->gameAudio.set_master(game->gameAudio.get_master() - 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            if(game->gameAudio.get_master() < 100){
                game->gameAudio.set_master(game->gameAudio.get_master() + 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_A:{
            std::cout << "Master volume control"<<std::endl;
            
            break;
        }
        
        default:{
            std::cerr<<"ERROR master volume invalid input"<<std::endl;
        }
    }

    game->gameAudio.saveSettings();

    reload();
    
    return;
}

void AudioMenu::Music(void){
    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            if(game->gameAudio.get_music() > 0){
                game->gameAudio.set_music(game->gameAudio.get_music() - 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            if(game->gameAudio.get_music() < 100){
                game->gameAudio.set_music(game->gameAudio.get_music() + 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_A:{
            std::cout << "Music volume control"<<std::endl;
            
            break;
        }
        
        default:{
            std::cerr<<"ERROR music volume invalid input"<<std::endl;
        }
    }

    game->gameAudio.saveSettings();

    reload();

    return;
}

void AudioMenu::Voices(void){
    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            if(game->gameAudio.get_voices() > 0){
                game->gameAudio.set_voices(game->gameAudio.get_voices() - 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            if(game->gameAudio.get_voices() < 100){
                game->gameAudio.set_voices(game->gameAudio.get_voices() + 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_A:{
            std::cout << "Voice volume control"<<std::endl;
            
            break;
        }
        
        default:{
            std::cerr<<"ERROR voice volume invalid input"<<std::endl;
        }
    }

    game->gameAudio.saveSettings();

    reload();

    return;
}

void AudioMenu::Effects(void){
    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:{
            if(game->gameAudio.get_effects() > 0){
                game->gameAudio.set_effects(game->gameAudio.get_effects() - 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:{
            if(game->gameAudio.get_effects() < 100){
                game->gameAudio.set_effects(game->gameAudio.get_effects() + 1);
            }
            
            break;
        }
        
        case SDL_CONTROLLER_BUTTON_A:{
            std::cout << "Effects volume control"<<std::endl;
            
            break;
        }
        
        default:{
            std::cerr<<"ERROR effects volume invalid input"<<std::endl;
        }
    }

    game->gameAudio.saveSettings();

    reload();
    
    game->gameAudio.play(menuClickSFX);

    return;
}

void AudioMenu::Default(void){
    std::cout<<"DEFAULT"<<std::endl;
    
    game->fileI.open(audioDefault);
    if(!game->fileI.is_open()){
        std::cerr<<"ERROR unable to open audio default file"<<std::endl;
    }
    else{
        int ma, mu, vo, ef;
        game->fileI>>std::dec>>ma>>mu>>vo>>ef;
        
        game->gameAudio.set_music(mu);
        game->gameAudio.set_voices(vo);
        game->gameAudio.set_effects(ef);
        
        game->gameAudio.set_master(ma);
        
        game->gameAudio.saveSettings();
        
        reload();
    }
    game->fileI.close();
    
    return;

    return;
}
