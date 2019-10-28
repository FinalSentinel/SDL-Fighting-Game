/*
 * VersusState.cpp
 *
 *  Created on: Aug 13, 2019
 *      Author: Clayton
 */

#include "VersusState.h"

#include "VersusMenu.h"

#include "Audio.h"
#include "Box.h"
#include "Character.h"
#include "Player.h"
#include "Texture.h"

VersusState::VersusState(int vMode, int vLevel, int vMusic):
				mode(vMode), level(vLevel), music(vMusic), camera(new SDL_Rect), stage(new Texture()){
	if((game->gameWindow.getWidth() * cameraConst) < game->gameWindow.getHeight()){
		renderW = game->gameWindow.getWidth();
		renderH = int(game->gameWindow.getWidth() * cameraConst);
		renderX = 0;
		renderY = ((game->gameWindow.getHeight() - renderH) / 2);
	}
	else{
		renderW = int(game->gameWindow.getHeight() / cameraConst);
		renderH = game->gameWindow.getHeight();
		renderX = ((game->gameWindow.getWidth() - renderW) / 2);
		renderY = 0;
	}

	for(int i = 0; i < ACTIVE_PLAYERS; i++){
		active[i] = nullptr;
	}
}

VersusState::~VersusState(void){
    delete camera;
    camera = nullptr;
};

//TODO switch to take vector of characters?
void VersusState::decollide(Character* c1, Character* c2){
	int col = 0;
	//TODO can I remove the wallb's?
	int floor1, floor2, wall1, wall1b, wall2, wall2b;

	//TODO double check
	bool side = (c1->get_x() < c2->get_x() || (c1->get_x() == c2->get_x() && c1->get_left()));
	bool specCondition = false;

	/*WALL COLLISION*/
	{
		//TODO ACTIVE_PLAYER for loop
		floor1 = floorCollision(c1);
		floor2 = floorCollision(c2);

		if(floor1){
			c1->set_dy(0);
		}
		if(floor2){
			c2->set_dy(0);
		}

		wall1 = wallDistance(c1, side);
		wall1b = wallDistance(c1, !side);

		wall2 = wallDistance(c2, !side);
		wall2b = wallDistance(c2, side);

		//TODO double check
		if(wall1 <= 0 && !c1->get_wall() && !c2->get_wall()){
			if(wall2 > 0 || (side && wall1 <= wall2) || (!side && wall1 > wall2)){
				c1->set_wall(true);
			}
		}
		else if(wall1 > 0 && wall1b > 0){
			c1->set_wall(false);
		}

		if(wall2 <= 0 && !c1->get_wall() && !c2->get_wall()){
			if(wall1 > 0 || (side && wall1 > wall2) || (!side && wall1 <= wall2)){
				c2->set_wall(true);
			}
		}
		else if(wall2 > 0 && wall2b > 0){
			c2->set_wall(false);
		}

		if(wall1 < 0 || wall2 < 0 || floor1 || floor2){
			c1->position((c1->get_x() - (wall1 * (wall1 < 0) - wall1b * (wall1b < 0)) * ((2 * side) - 1)), c1->get_y() - floor1);
			c2->position((c2->get_x() + (wall2 * (wall2 < 0) - wall2b * (wall2b < 0)) * ((2 * side) - 1)), c2->get_y() - floor2);
		}
	}
    
    /*CHARACTER COLLISION*/
	{
		for(unsigned int i = 0; i < c1->getBoxes(COLLISION).size(); i++){
			for(unsigned int j = 0; i < c2->getBoxes(COLLISION).size(); i++){
				if(c1->getBoxes(COLLISION)[i].collides(c2->getBoxes(COLLISION)[j])){
					specCondition = ((wall1 < 0 && (wall2 + c2->getBoxes(COLLISION)[j].get_w()) >= game->gameWindow.getWidth()) || ((wall1 + c1->getBoxes(COLLISION)[i].get_w()) >= game->gameWindow.getWidth() && wall2 < 0));
					if((side && !specCondition) || (!side && specCondition)){
						col = std::max(col, ((c1->getBoxes(COLLISION)[i].get_x() + c1->getBoxes(COLLISION)[i].get_w()) - c2->getBoxes(COLLISION)[j].get_x()));
					}
					else{
						col = std::min(col, (c1->getBoxes(COLLISION)[i].get_x() - (c2->getBoxes(COLLISION)[j].get_x() + c2->getBoxes(COLLISION)[j].get_w())));
					}
				}
			}
		}
	}

	/*COLLISION MOVEMENT*/
	{
		/*  c1->position((c1->get_x()), c1->get_y());
			c2->position((c2->get_x()), c2->get_y());  */

		if(col){
			wall1 *= (wall1 > 0);
			wall2 *= (wall2 > 0);

			if(wall1 < std::abs((col + 0.5) / 2)){
				if(wall2 < std::abs(col / 2)){
					//DO NOTHING
				}
				else{
					if(c1->get_wall()){
						c1->position((c1->get_x()      ), c1->get_y());
						c2->position((c2->get_x() + col), c2->get_y());
					}
					else if(c2->get_wall()){
						c1->position((c1->get_x() - col), c1->get_y());
						c2->position((c2->get_x()      ), c2->get_y());
					}
					else{
						c1->position((c1->get_x()       - wall1 * ((2 * side) - 1)), c1->get_y());
						c2->position((c2->get_x() + col - wall1 * ((2 * side) - 1)), c2->get_y());
					}
				}
			}
			else if(wall2 < std::abs((col + 0.5) / 2)){
				if(c1->get_wall()){
					c1->position((c1->get_x()      ), c1->get_y());
					c2->position((c2->get_x() + col), c2->get_y());
				}
				else if(c2->get_wall()){
					c1->position((c1->get_x() - col), c1->get_y());
					c2->position((c2->get_x()      ), c2->get_y());
				}
				else{
					c1->position((c1->get_x() - col + wall2 * ((2 * side) - 1)), c1->get_y());
					c2->position((c2->get_x()       + wall2 * ((2 * side) - 1)), c2->get_y());
				}
			}
			else{
				c1->position((c1->get_x() - ((col + 0.5 *  side) / 2)), c1->get_y());
				c2->position((c2->get_x() + ((col + 0.5 * !side) / 2)), c2->get_y());
			}
		}
	}
    
    /*SIDE DETECTION*/
	{
		//TODO  Reorient boxes to check from bottom left.
		if(c1->get_x() != c2->get_x()){
			if(c1->get_y() + 100 >= game->gameWindow.getHeight()){
				c1->set_left(c1->get_x() < c2->get_x());
			}
			if(c2->get_y() + 100 >= game->gameWindow.getHeight()){
				c2->set_left(c1->get_x() > c2->get_x());
			}
		}
	}

    return;
}

int VersusState::floorCollision(Character* c) const{
	//Decollide from floor.
	int colY = 0;
	for(unsigned int i = 0; i < c->getBoxes(COLLISION).size(); i++){
		//If character's collision box is beyond the stage floor.
		if((c->getBoxes(COLLISION)[i].get_y() + c->getBoxes(COLLISION)[i].get_h()) > game->gameWindow.getHeight()){
			//Find the greatest abs. collision height.
			colY = std::max(colY, (c->getBoxes(COLLISION)[i].get_y() + c->getBoxes(COLLISION)[i].get_h() - game->gameWindow.getHeight()));
		}
	}

	return colY;
}

void VersusState::load(void){
    //TODO
    std::cout << "VERSUS STATE" << std::endl;
    
    for(unsigned int i = 0; i < ACTIVE_PLAYERS && i < game->getPlayersList().size(); i++){
        //TODO start characters closer together so origin point for characters not in middle?
        //TODO Let players choose active slot
        active[i] = game->getPlayersList()[i];
        if(i < (ACTIVE_PLAYERS + 1) / 2){
            //First half of players start with left-side.
            active[i]->character = new Character(game->getPlayersList()[i]->get_character(),
                                                 (i + 1) * renderW / (ACTIVE_PLAYERS + 1),
												 renderY + renderH,
												 true);
        }
        else{
            //Last half of players start with right-side.
            active[i]->character = new Character(game->getPlayersList()[i]->get_character(),
                                                 (i + 1) * renderW / (ACTIVE_PLAYERS + 1),
												 renderY + renderH,
												 false);
        }
        //TODO dynamic starting position
        //TODO proper box loading
		//TODO boxes at mid of character
        active[i]->character->addBox(COLLISION, 0/*-(130 - (10 * game->getPlayersList()[i]->get_character()))/2*/,
												0,
												100/*130 - (10 * game->getPlayersList()[i]->get_character())*/,
                                                100/*70 + (10 * game->getPlayersList()[i]->get_character())*/);
    }
    
    //TODO different stages
    if(!stage->loadImage(game->gameWindow.renderer, "defStage.png")){
        std::cerr << "ERROR stage not loaded correctly" << std::endl;
    }
    
    //TODO game unit based values
    if((stage->get_w() * stageConst) < stage->get_h()){
        *camera = {int(stage->get_w() * stageConst), 
                   int(stage->get_w() * stageConst / cameraConst), 
                   int(stage->get_w() * (1 - (2 * stageConst))),
                   int(stage->get_h() * (1 - (2 * stageConst)))   };
    }
    else{
        *camera = {int(stage->get_w() * stageConst), 
                   int(stage->get_w() * stageConst * cameraConst), 
                   int(stage->get_w() * (1 - (2 * stageConst))),
                   int(stage->get_h() * (1 - (2 * stageConst)))   };
    }
    
    //TODO different musics
    Mix_FadeOutMusic(30);

    return;
}

//FIXME FIX THIS SO THAT IT DOESN'T DEPEND ON ORDER
//FIXME Fix for hypothetical box larger than camera.
//Switch to Character** and loop inside function?
void VersusState::moveCamera(Character* c){
    int colX = 0, colY = 0;
    
    for(unsigned int i = 0; i < c->getBoxes(COLLISION).size(); i++){
        if(c->getBoxes(COLLISION)[i].get_x() < 0){
            colX = std::max(colX, (0 - c->getBoxes(COLLISION)[i].get_x()));
        }
        else if((c->getBoxes(COLLISION)[i].get_x() + c->getBoxes(COLLISION)[i].get_w()) > game->gameWindow.getWidth()){
            colX = std::min(colX, (game->gameWindow.getWidth() - (c->getBoxes(COLLISION)[i].get_x() + c->getBoxes(COLLISION)[i].get_w())));
        }
        
        if(c->getBoxes(COLLISION)[i].get_y() < 0){
            colY = std::max(colY, (0 - c->getBoxes(COLLISION)[i].get_y()));
        }
        else if((c->getBoxes(COLLISION)[i].get_y() + c->getBoxes(COLLISION)[i].get_h()) > game->gameWindow.getHeight()){
            colY = std::min(colY, (game->gameWindow.getHeight() - (c->getBoxes(COLLISION)[i].get_y() + c->getBoxes(COLLISION)[i].get_h())));
        }
    }
    
    camera->x -= ((stage->get_w() * colX) / STAGE_WIDTH);
    camera->y -= ((stage->get_h() * colY) / STAGE_HEIGHT);
    
    if(camera->x < 0){
        camera->x = 0;
    }
    else if((camera->x + camera->w) > stage->get_w()){
        camera->x = stage->get_w() - camera->w;
    }
    
    if(camera->y < 0){
        camera->y = 0;
    }
    else if((camera->y + camera->h) > stage->get_h()){
        camera->y = stage->get_h() - camera->h;
    }
    
    return;
}

std::string VersusState::name(void) const{
    return "VersusState";
}

void VersusState::pause(void){
    //TODO pause timers and shit?
    
    return;
}

void VersusState::render(void) const{
    SDL_RenderClear(game->gameWindow.renderer);
    
	//TODO camera fix stuff
    stage->render(game->gameWindow.renderer, renderX, renderY, renderW, renderH/*, camera*/);
    
    for(unsigned int i = 0; i < ACTIVE_PLAYERS; i++){
        active[i]->character->render(game->gameWindow.renderer);
    }

    return;
}

void VersusState::resume(void){
    //TODO
    return;
}

void VersusState::unload(void){
    //TODO
    return;
}

void VersusState::update(void){
    //TODO pass to character/player input handler?
    //TODO frame based logic
    //TODO get P1 P2 state for keyboard/controller
    //TODO Active players slots
    for(unsigned int i = 0; i < ACTIVE_PLAYERS; i++){
        if(active[i]->controller != nullptr){
            if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_LEFT)){
                active[i]->character->set_dx(-10);
            }
            else if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_RIGHT)){
                active[i]->character->set_dx(10);
            }
            else{
                active[i]->character->set_dx(0);
            }
            
            if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_UP)){
                active[i]->character->set_dy(-10);
            }
            else if(SDL_GameControllerGetButton(active[i]->controller, SDL_CONTROLLER_BUTTON_DPAD_DOWN)){
                //TODO if y + h >= STAGE_HEIGHT then crouch.
                if(active[i]->character->get_dy() < 0 || active[i]->character->get_y() < game->gameWindow.getHeight()){
                    active[i]->character->set_dy(active[i]->character->get_dy() + 1);
                }
            }
            else if(active[i]->character->get_dy() < 0 || active[i]->character->get_y() < game->gameWindow.getHeight()){
                active[i]->character->set_dy(active[i]->character->get_dy() + 1);
            }
        }
        else{
            const Uint8* keys = SDL_GetKeyboardState(NULL);

            //TODO Key player associations
            //If key pressed... else...
            /*
            if(keys[SDL_SCANCODE_]){

            }
            else{

            }
             */
            if(keys[SDL_SCANCODE_A] && !keys[SDL_SCANCODE_D]){
                active[i]->character->set_dx(-10);
            }
            else if(keys[SDL_SCANCODE_D] && !keys[SDL_SCANCODE_A]){
                active[i]->character->set_dx(10);
            }
            else{
                active[i]->character->set_dx(0);
            }

            if(keys[SDL_SCANCODE_S] && !keys[SDL_SCANCODE_W]){
                //CROUCH STUFF
            }
            else if(keys[SDL_SCANCODE_W] && !keys[SDL_SCANCODE_S]){
                active[i]->character->set_dy(-10);
            }
            else if(active[i]->character->get_dy() < 0 || active[i]->character->get_y() < game->gameWindow.getHeight()){
                active[i]->character->set_dy(active[i]->character->get_dy() + 1);
            }
        }

        active[i]->character->move();
        //moveCamera(active[i]->character);
    }

    //TODO separate wall/character collision functions?
    //FIXME FUNCTION DOES NOT GUARANTEE PERFECT DECOLLISION FOR >2 CHARACTERS.
    //Handle character/wall collision.
    for(unsigned int i = 0; i < ACTIVE_PLAYERS; i++){
        for(unsigned int j = i + 1; j < ACTIVE_PLAYERS; j++){
            decollide(active[i]->character, active[j]->character);
        }
    }

    //TODO more update stuff

    return;
}

int VersusState::wallDistance(Character* c, const bool left) const{
	//Get smallest distance from wall
	int w = 0;
	bool set = false;

	for(unsigned int i = 0; i < c->getBoxes(COLLISION).size(); i++){
		if(left){
			w = (!set ? (c->getBoxes(COLLISION)[i].get_x() - 0) : std::min(w, c->getBoxes(COLLISION)[i].get_x() - 0));
		}
		else{
			w = (!set ? (game->gameWindow.getWidth() - (c->getBoxes(COLLISION)[i].get_x() + c->getBoxes(COLLISION)[i].get_w())) : std::max(w, (game->gameWindow.getWidth() - (c->getBoxes(COLLISION)[i].get_x() + c->getBoxes(COLLISION)[i].get_w()))));
		}

		if(!set){
			set = (w != 0);
		}
	}

	return w;
}

void VersusState::controllerAxisHandler(void){

    
    return;
}

//TODO move to Entity/Character class for easy use in other states (e.g. Character Select).
void VersusState::controllerButtonHandler(void){
    //TODO multiple control method exclusion
    //TODO player differentiation

    switch(game->e.cbutton.button){
        case SDL_CONTROLLER_BUTTON_A:
            break;

        case SDL_CONTROLLER_BUTTON_B:
            break;

        case SDL_CONTROLLER_BUTTON_X:
            break;

        case SDL_CONTROLLER_BUTTON_Y:
            break;

        case SDL_CONTROLLER_BUTTON_BACK:
            break;

        case SDL_CONTROLLER_BUTTON_GUIDE:
            break;

        case SDL_CONTROLLER_BUTTON_START:
            if(game->e.cbutton.type == SDL_CONTROLLERBUTTONDOWN){
                game->pushState(new VersusMenu(mode));
            }
            break;

        case SDL_CONTROLLER_BUTTON_LEFTSTICK:
            //FIXME Doesn't work on PS4 mode
            break;

        case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
            //FIXME Doesn't work on PS4 mode
            break;

        case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
            break;

        case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
            break;
            /*
                    case SDL_CONTROLLER_BUTTON_DPAD_UP:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
                            break;

                    case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
                            break;
             */
        case SDL_CONTROLLER_BUTTON_MAX:
            break;

        default:
            break;
    }

    return;
}

//TODO CONTROLLER DEVICE handler

void VersusState::keyHandler(void){
    //TODO multiple control method exclusion
    //TODO player differentiation

    //TODO key repeat handling
    if(!game->e.key.repeat){
        //TODO state based handling
        //NOTE setup two control list profiles and when keyboard is pressed do stuff
        switch(game->e.key.keysym.sym){
                //TODO pass to character input handler?
            case SDLK_a:
                if(game->e.type == SDL_KEYDOWN){
                }
                break;

            case SDLK_d:
                if(game->e.type == SDL_KEYDOWN){
                }
                break;

            case SDLK_s:
                break;

            case SDLK_w:
                if(game->e.type == SDL_KEYDOWN){
                }
                break;

            default:
                break;
        }
    }
    return;
}

void VersusState::windowHandler(void){
    //TODO
    return;
}
