#include "soldier.hpp"
#include <math.h>

namespace tbyte {
    namespace rts {
        namespace mob {
            Soldier::Soldier(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos): Mob(spritesheet, bounds, pos), moving(false), moveTarget({0, 0}), selected(false){
                ge::data->config.get("allyBounds", idleBounds);
                ge::data->config.get("enemyBounds", selectedBounds);
            }
            
            Soldier::~Soldier(){

            }

            void Soldier::update() {
                if(!selected) {
                    bounds = idleBounds;
                }
                else{
                    bounds = selectedBounds;
                }
                if(moving && moveTarget.x != 0 && moveTarget.y != 0){
                    if(getCenter().x == moveTarget.x && getCenter().y == moveTarget.y){
                        moving = false;
                        moveTarget = {0, 0};
                        return;
                    }
                    moveTo(moveTarget, 1.0);
                }
            }

            void Soldier::setSelected(bool val) {
                selected = val;
            }

            void Soldier::startMove(int targetX, int targetY) {
                if(!selected){ return; }
                moveTarget = {targetX - center.x, targetY - center.y};
                moving = true;
            }

            void Soldier::setMoving(bool newMoving){
                moving = newMoving;
            }

            bool Soldier::getSelected(){ return selected; }
        }
    }
}