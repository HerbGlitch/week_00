#include "handler.hpp"
#include "../../ui/handler.hpp"
#include "../handler.hpp"
#include <iostream>

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
            }

            void Handler::update(){
                ge::Handler<ge::Entity>::update();
                refreshQuadTree();

                spawnUnit();
                check();

                if(uiData->mouse.leftReleased){
                    SDL_Rect selectorArea = uiData->selectedArea;

                    if(mGroup){ delete mGroup; }
                    mGroup = new Group();

                    for(ge::Entity *entity : hTypes){
                        if(entity->collides(selectorArea) && ((Mob *)entity)->getID() == 1){

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

            void Handler::refreshQuadTree(){
                delete quadTree;
                quadTree = new ge::QuadTree(bounds);
                for(ge::Entity *e : hTypes){ quadTree->insert(e); }
            }

            void Handler::spawnUnit(){
                int type = 0;
                if(ge::data->keyboard.getRelease(SDLK_1)){ type = 1; }
                if(ge::data->keyboard.getRelease(SDLK_2)){ type = 2; }
                if(!type){ return; }

                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                GE_Scale *scale;
                ge::data->config.get(GE_VAR_STR(scale));

                GE_Bounds *solderBounds;
                if(type == 1){
                    ge::data->config.get("player", solderBounds);
                }
                else {
                    ge::data->config.get("enemy", solderBounds);
                }
                
                GE_Sheet *spritesheet;
                ge::data->config.get(GE_VAR_STR(spritesheet));

                GE_Sprite *sprite = new GE_Sprite { spritesheet, solderBounds };
                if(type == 1){
                    Soldier *soldier = new Soldier(sprite, SDL_Point { uiData->mouse.x, uiData->mouse.y }, *scale, type);
                    add(soldier);
                    quadTree->insert(soldier);
                }
                else {
                    Enemy *enemy = new Enemy(sprite, SDL_Point { uiData->mouse.x, uiData->mouse.y }, *scale, type);
                    add(enemy);
                    quadTree->insert(enemy);
                }

            }

            void Handler::check(){
                for(ge::Entity *entity : hTypes){
                    if(((Mob *)entity)->getHealth() <= 0) {
                        remove(entity);
                    }
                    bool vis = checkVision((Mob *)entity);
                    if(vis){
                        checkCollision((Mob *)entity);
                    }
                }
            }

            bool Handler::checkVision(Mob *mob){
                std::vector<ge::Entity *> closeMobs;
                quadTree->query(mob->getHitbox(), closeMobs);
                for(ge::Entity *entity : closeMobs){
                    Mob *other = (Mob *)entity;

                    if(other != mob){
                        SDL_Rect *colBounds = other->getHitbox();

                        SDL_Rect vision = mob->getVision();
                        if(mob->getID() != other->getID() && SDL_HasIntersection(&vision, &(other->getBounds()))){
                            ((Soldier *)mob)->setSeeSoldier(other);
                            return true;
                        }
                    }
                }
                return false;
            }

            void Handler::checkCollision(Mob *mob){
                for(ge::Entity *entity : hTypes) {
                    GE_Bounds *center = mob->getHitbox();

                    std::vector<ge::Entity *> closeMobs;
                    quadTree->query(mob->getHitbox(), closeMobs);
                    for(ge::Entity *entity : closeMobs){
                        Mob *other = (Mob *)entity;

                        SDL_Rect *colBounds = other->getHitbox();

                        if(mob->getID() == other->getID() && mob->collides(colBounds)) {
                            // KENNY GIVE ME SOME EVASIVE FUCKING MANEUVERS
                        }

                        if(other->id == 3){
                            std::cout << "YOU'VE HIT A FUCKING WALL DUMBASS " << std::endl;
                            ((Soldier *)mob)->setMoving(false);
                        }
                        
                        if(mob->getID() != other->getID() && mob->collides(colBounds)){
                            ((Soldier *)mob)->setTarget(other);
                        }
                    }
                }
            }

        }
    }
}