#include "handler.hpp"
#include "../../ui/ui.hpp"
#include "../handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(Surfaces *surfaces): surfaces(surfaces), speed(0.007f), current(0.0f){
            }

            Handler::~Handler(){
                // SDL_DestroyTexture(spritesheet);
            }

            void Handler::update() {
                ui::Handler *uiHandler = surfaces->uiHandler;
                ge::Handler<ge::Sprite>::update();

                if (ge::data->keyboard.getPress(SDLK_1)){
                    spawnUnit();
                }
                if(uiHandler->getShouldUpdate()){
                    SDL_Rect selectorArea = uiHandler->getSelectedArea();
                    // check if units are in selector area
                    for(ge::Sprite *object : hTypes){
                        bool selected = SDL_HasIntersection(&selectorArea, &object->getPos());
                        ((Soldier *)object)->setSelected(selected);
                        if(selected){
                            ((Soldier *)object)->startMove(uiHandler->movePoint.x, uiHandler->movePoint.y);
                        }
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