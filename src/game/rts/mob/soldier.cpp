#include "soldier.hpp"
#include <math.h>

namespace tbyte {
    namespace rts {
        namespace mob {
            Soldier::Soldier(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos): Mob(spritesheet, bounds, pos), moving(false), target({0,0}), selected(false){

            }
            
            Soldier::~Soldier(){

            }

            void Soldier::update() {
                if(moving){
                    if(getPos().x == target.x && getPos().y == target.y){
                        moving = false;
                        return;
                    }
                    moveTo(target, 1.0);
                }
            }

            void Soldier::setSelected(bool val) {
                selected = val;
            }

            void Soldier::startMove(int targetX, int targetY) {
                if(!selected){ return; }

                // float b = targetX - bounds.x;
                // float a = targetY - bounds.y;
                // float dist = sqrt(a * a + b * b);
                target = {targetX, targetY};
                moving = true;
            }
        }
    }
}