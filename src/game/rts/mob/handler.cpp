#include "handler.hpp"
#include "../../ui/handler.hpp"
#include "../handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(Surfaces *surfaces, rts::Data *data, ui::Data *uiData): surfaces(surfaces), data(data), uiData(uiData), speed(0.007f), current(0.0f), mGroup(nullptr){
                offset = data->offset;
                GE_ColorGrid *tempMap;
                ge::data->config.get(GE_VAR_STR(tempMap));

                bounds = { 0, 0, (int)tempMap->w * 32, (int)tempMap->h * 32 };
                quadTree = new ge::QuadTree(bounds);
            }

            Handler::~Handler(){
                delete quadTree;
                // if(mGroup) { 
                //     delete mGroup;
                // }
            }

            void Handler::update(){
                ui::Handler *uiHandler = surfaces->uiHandler;

                for(ge::Entity *entity : hTypes){
                    Soldier *soldier = ((Soldier *)entity);
                    if(soldier->getMoving()){
                        GE_Bounds center = GE_Bounds { soldier->getCenter().x, soldier->getCenter().y, soldier->getCenter().x, soldier->getCenter().y };
                        center.x -= soldier->getBounds().w * 2;
                        center.y -= soldier->getBounds().h * 2;
                        center.w += soldier->getBounds().w * 2;
                        center.h += soldier->getBounds().h * 2;

                        std::vector<ge::Entity *> closeMobs;
                        quadTree->query(&center, closeMobs);

                        for(ge::Entity *sol : closeMobs){
                            Soldier *colSoldier = ((Soldier *)sol);
                            if(colSoldier != soldier) {
                                if(soldier->collides(colSoldier->getBounds())){
                                    soldier->setMoving(false);
                                }
                            }
                        }
                    }
                }

                ge::Handler<ge::Entity>::update();

                delete quadTree;
                quadTree = new ge::QuadTree(bounds);
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

                if(ge::data->keyboard.getRelease(SDLK_q)){
                    if(mGroup){
                        for(Mob *mob : mGroup->getMobs()){
                            ge::Entity *test = (ge::Entity *)mob;
                            remove(test);
                            delete mGroup;
                            mGroup = nullptr;
                        }
                    }
                }

                if(mGroup){ mGroup->update(); }
            }

            void Handler::render(){
                ge::Surface::render();
                quadTree->render(*offset);
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