#include "handler.hpp"
#include "../../ui/ui.hpp"
#include "../handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(Surfaces *surfaces, ui::Data *uiData): surfaces(surfaces), uiData(uiData), speed(0.007f), current(0.0f), mGroup(nullptr){
            }

            Handler::~Handler(){
                // if(mGroup) { 
                //     delete mGroup;
                // }
            }

            void Handler::update(){
                ui::Handler *uiHandler = surfaces->uiHandler;
                ge::Handler<ge::Entity>::update();

                if (ge::data->keyboard.getRelease(SDLK_1)){
                    spawnUnit();
                }

                // for(ge::Entity *entity : hTypes){
                //     Soldier *soldier = ((Soldier *)entity);
                //     if(soldier->getMoving()){
                //         for(ge::Entity *sol : hTypes){
                //             Soldier *colSoldier = ((Soldier *)sol);
                //             if(colSoldier != soldier) {
                //                 if(soldier->collides(colSoldier->getBounds())){
                //                     // soldier->setMoving(false);
                //                 }
                //             }
                //         }
                //     }
                // }


                
                if(uiData->mouse.leftReleased){
                    SDL_Rect selectorArea = uiHandler->getSelectedArea();

                    if(mGroup){ 
                        delete mGroup; 
                    }
                    mGroup = new Group();

                    for(ge::Entity *entity : hTypes){
                        if(entity->collides(selectorArea)){

                            ((Soldier *)entity)->setSelected(true);
                            mGroup->addMob((Mob *)entity);
                        }
                    }

                    if(mGroup->empty()){
                        delete mGroup;
                        mGroup = nullptr;
                    }
                }

                if(uiData->mouse.rightReleased){
                    if(mGroup){ mGroup->addCoord({ uiData->mouse.x, uiData->mouse.y }); }
                }

                if(mGroup){ mGroup->update(); }
            }

            void Handler::spawnUnit(){
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                GE_Scale *scale;
                ge::data->config.get(GE_VAR_STR(scale));

                GE_Bounds *solderBounds;
                ge::data->config.get("player", solderBounds);
                
                GE_Sheet *spritesheet;
                ge::data->config.get(GE_VAR_STR(spritesheet));

                GE_Sprite *sprite = new GE_Sprite { spritesheet, solderBounds };
                add(new Soldier(sprite, SDL_Point { ge::data->mouse.x, ge::data->mouse.y }, *scale));
            }
        }
    }
}