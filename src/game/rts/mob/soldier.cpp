#include "soldier.hpp"
#include <math.h>
#include <iostream>

namespace tbyte {
    namespace rts {
        namespace mob {
            Soldier::Soldier(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale, int id): Mob(sprite, pos, scale, id, 100), selected(false){
            }

            Soldier::~Soldier(){

            }

            void Soldier::update() {
                if(!canAttack){
                    timeKeep += ge::data->dt;
                    if(timeKeep > 333) {
                        timeKeep = 0;
                        canAttack = true;
                    }
                }
                if(state == MOVING){
                    bool stop = moveTo(moveTarget, 1.0);
                    if(stop){
                        moveTarget = { 0, 0 };
                        state = IDLE;
                    }
                }
                if(state == ATTACK) {
                    if(target->getHealth() <= 0) {
                        target = nullptr;
                        state = IDLE;
                        return;
                    }
                    // bool ss = collides(target->getHitbox());
                    if(canAttack) {
                        attack(target, 20);
                        canAttack = false;
                    }
                    // do attack shit
                }
                if(state == IDLE) {
                    // play jerk off animation or some shit idk
                }
            }

            void Soldier::attack(Mob *target, int damage){
                if(!target) {
                    state = IDLE;
                    return;
                }
                std::cout << "S: attack" << std::endl;
                bool ded = target->getAttacked(this, damage);
                if(ded){
                    target = nullptr;
                }
            }

            bool Soldier::getAttacked(Mob *target, int damage){
                // todo reduce damage by armor or some shit
                health = health - damage;
                std::cout << "Got hit hp sol: " << health << std::endl;
                return health <= 0;
            }

            void Soldier::setSelected(bool selected) {
                this->selected = selected;
            }

            void Soldier::startMove(int targetX, int targetY) {
                if(!selected){ return; }
                if(moveTarget.x == targetX - getBounds().w / 2 && moveTarget.y == targetY - getBounds().h / 2 ){ return; }

                moveTarget = {targetX - center.x, targetY - center.y};
                state = MOVING;
            }

            void Soldier::setMoving(bool moving){
                state = moving ? MOVING : IDLE; 
            }
            bool Soldier::getMoving(){ return state == MOVING; }

            void Soldier::setAttacking(){ 
                state = ATTACK; 
            }

            bool Soldier::getSelected(){ return selected; }

            void Soldier::setTarget(Mob *&enemy){
                if(state == IDLE || state == MOVING){
                    target = enemy;
                    if(collides(enemy->getHitbox())){
                        setMoving(false);
                    }
                    setAttacking();
                }
            }

            void Soldier::setSeeSoldier(Mob *sol){
                if(sol->getID() != id){
                    if(state != MOVING){
                        setTarget(sol);
                    }
                }
                else {
                    // move around if not hit goal, else stop
                }
            }
        }
    }
}