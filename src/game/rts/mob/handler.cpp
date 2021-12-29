#include "handler.hpp"
#include "../../ui/handler.hpp"
#include "../handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(Surfaces *surfaces, rts::Data *data, ui::Data *uiData): surfaces(surfaces), data(data), uiData(uiData), speed(0.007f), current(0.0f), mGroup(nullptr){
                offset = data->offset;
                quadTree = new ge::QuadTree(ge::data->windowSize);
            }

            Handler::~Handler(){
                delete quadTree;
                // if(mGroup) { 
                //     delete mGroup;
                // }
            }

            void Handler::update(){
                ui::Handler *uiHandler = surfaces->uiHandler;
                ge::Handler<ge::Entity>::update();

                delete quadTree;
                quadTree = new ge::QuadTree(ge::data->windowSize);
                for(ge::Entity *e : hTypes){ quadTree->insert(e); }


                if (ge::data->keyboard.getRelease(SDLK_1)){
                    spawnUnit();
                }

                if(uiData->mouse.leftReleased){
                    SDL_Rect selectorArea = uiHandler->getSelectedArea();

                    if(mGroup){ delete mGroup; }
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

            void Handler::render(){
                ge::Surface::render();
                quadTree->render();
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
                Soldier *soldier = new Soldier(sprite, SDL_Point { uiData->mouse.x, uiData->mouse.y }, *scale);

                add(soldier);
                quadTree->insert(soldier);
            }
        }
    }
}