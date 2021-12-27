#include "handler.hpp"
#include "../../ui/ui.hpp"
#include "../handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(Surfaces *surfaces): surfaces(surfaces), speed(0.007f), current(0.0f){
            }

            Handler::~Handler(){
                if(mGroup) { 
                    delete mGroup;
                }
            }

            void Handler::update(){
                ui::Handler *uiHandler = surfaces->uiHandler;
                ge::Handler<ge::Entity>::update();

                if (ge::data->keyboard.getRelease(SDLK_1)){
                    spawnUnit();
                }

                for(ge::Entity *entity : hTypes){
                    Soldier *soldier = ((Soldier *)entity);
                    if(soldier->moving){
                        for(ge::Entity *sol : hTypes){
                            Soldier *colSoldier = ((Soldier *)sol);
                            if(colSoldier != soldier) {
                                if(soldier->collides(colSoldier->getPos())){
                                    // soldier->setMoving(false);
                                }
                            }
                        }
                    }
                }
                
                if(uiHandler->getShouldUpdate()){
                    SDL_Rect selectorArea = uiHandler->getSelectedArea();
                    mGroup = nullptr;

                    for(ge::Entity *entity : hTypes){
                        bool selected = ((ge::Sprite *)entity)->collides(selectorArea);
                        Soldier *soldier = ((Soldier *)entity);
                        if(!mGroup){
                            mGroup = new MobGroup();
                            mGroup->current = {uiHandler->getData()->movePoint.x, uiHandler->getData()->movePoint.y};
                        }
                        soldier->setSelected(selected);
                        if(selected){
                            float targetX = mGroup->current.x;
                            float targetY = mGroup->current.y;
                            float b = targetX - soldier->getBounds().x;
                            float a = targetY - soldier->getBounds().y;
                            float dist = sqrt(a * a + b * b);
                            auto pos = std::find_if(mGroup->mobs.begin(), mGroup->mobs.end(), [dist, targetX, targetY](auto curEnt) {
                                float b = targetX - ((Soldier *)curEnt)->getBounds().x;
                                float a = targetY - ((Soldier *)curEnt)->getBounds().y;
                                float curDist = sqrt(a * a + b * b);
                                return curDist < dist;
                            });
                            mGroup->mobs.insert(pos, ((Mob *)entity));
                        }
                    }
                    getcoordsFromGroup();
                }
            }

            void Handler::getcoordsFromGroup(){
                ui::Handler *uiHandler = surfaces->uiHandler;
                float formationWidth = mGroup->mobs.size() * 32;
                SDL_Point formationBounds = getAvailableSpace(mGroup->mobs.size());
                float currentX = mGroup->current.x - formationBounds.x / 2;
                float currentY = mGroup->current.y - formationBounds.y / 2;
                for(Mob *entity: mGroup->mobs){
                    ((Soldier *)entity)->startMove(currentX, mGroup->current.y);
                    currentX += ((Soldier *)entity)->getBounds().w;
                }
            }

            SDL_Point Handler::getAvailableSpace(int numUnits) {
                return { 32 * 4, 32 * 3 };
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