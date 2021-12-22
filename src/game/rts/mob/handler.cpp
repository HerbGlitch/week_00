#include "handler.hpp"
#include "../../ui/ui.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(ge::Surface **states): states(states), speed(0.007f), current(0.0f){
            }

            Handler::~Handler(){
                // SDL_DestroyTexture(spritesheet);
            }

            void Handler::update() {
                ui::Handler *uiHandler = (ui::Handler *)states + 2;
                ge::Handler<ge::Sprite>::update();

                if (ge::data->keyboard.getRelease(SDLK_1)) {
                    spawnUnit();
                }
                if(uiHandler->getShouldUpdate()){

                    // check if units are in selector area

                    for(ge::Sprite *object : hTypes){
                        ((Soldier *)object)->startMove(uiHandler->movePoint.x, uiHandler->movePoint.y);
                    }
                }
            }

            void Handler::spawnUnit(){
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                int scale;
                ge::data->config.get(GE_VAR_STR(scale));

                add(new Soldier(spritesheet, "allyBounds", SDL_Point { ge::data->mouse.x, ge::data->mouse.y }));

            }
        }
    }
}