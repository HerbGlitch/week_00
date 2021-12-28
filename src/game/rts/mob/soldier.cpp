#include "soldier.hpp"
#include <math.h>

namespace tbyte {
    namespace rts {
        namespace mob {
            Soldier::Soldier(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale): Mob(sprite, pos, scale), moving(false), moveTarget({0, 0}), selected(false){
            }

            Soldier::~Soldier(){

            }

            void Soldier::update() {
                // if(moving){
                //     moving = moveTo(moveTarget, 1.0);
                //     if(!moving){
                //         moveTarget = { 0, 0 };
                //     }
                // }
            }

            void Soldier::setSelected(bool val) {
                selected = val;
            }

            void Soldier::startMove(int targetX, int targetY) {
                if(!selected){ return; }
                moveTarget = {targetX - center.x, targetY - center.y};
                moving = true;
            }

            void Soldier::setMoving(bool moving){ this->moving = moving; }
            bool Soldier::getMoving(){ return moving; }

            bool Soldier::getSelected(){ return selected; }
        }
    }
}