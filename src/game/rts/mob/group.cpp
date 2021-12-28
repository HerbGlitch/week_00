#include "group.hpp"
#include <algorithm>
#include <math.h>

namespace tbyte {
    namespace rts {
        namespace mob {
            Group::Group(): moving(false){}

            void Group::addMob(Mob *mob){
                float b = current.x - mob->getBounds().x;
                float a = current.y - mob->getBounds().y;
                float dist = sqrt(a * a + b * b);
                auto pos = std::find_if(mobs.begin(), mobs.end(), [dist, this](Mob *curEnt) {
                    float b = current.x - curEnt->getBounds().x;
                    float a = current.y - curEnt->getBounds().y;
                    return sqrt(a * a + b * b) > dist;
                });
                mobs.insert(pos, mob);
            }

            void Group::addCoord(SDL_Point pos){
                current = pos;
                moving = true;

                for(Mob *&mob : mobs){ ((Soldier *)mob)->setMoving(true); }
            }

            void Group::update(){
                if(moving){
                    moving = false;
                    for(uint32_t i = 0; i < mobs.size(); i++){
                        if(((Soldier *)mobs.at(i))->getMoving()){
                            moving = true;
                            if(mobs.at(i)->moveTo({(((int)i * 32) + current.x), current.y}, 1.0f)){
                                ((Soldier *)mobs.at(i))->setMoving(false);
                            }
                        }
                    }
                }
            }

            bool Group::empty(){ return mobs.empty(); }
        }
    }
}