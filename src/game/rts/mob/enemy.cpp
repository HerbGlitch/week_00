#include "enemy.hpp"
#include <math.h>
#include <iostream>

namespace tbyte {
    namespace rts {
        namespace mob {
            Enemy::Enemy(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale, int id): Mob(sprite, pos, scale, id, 100), selected(false){
            }

            Enemy::~Enemy(){

            }

            void Enemy::update() {
                if(state == MOVING){
                    bool moving = moveTo(moveTarget, 1.0);
                    if(!moving){
                        moveTarget = { 0, 0 };
                        state = IDLE;
                    }
                }
                if(state == ATTACK) {
                    // do attack shit
                }
                if(state == IDLE) {
                    // play jerk off animation or some shit idk
                }
            }

            void Enemy::attack(Mob *target, int damage){
                std::cout << "E: attack" << std::endl;
                target->getAttacked(this, damage);
            }

            bool Enemy::getAttacked(Mob *target, int damage){
                // todo reduce damage by armor or some shit
                health = health - damage;
                std::cout << "Got hit hp: " << health << std::endl;
                if(health <= 0){
                }
                return health <= 0;

            }
      
            void Enemy::setSelected(bool selected) {
                this->selected = selected;
            }

            void Enemy::startMove(int targetX, int targetY) {
                if(!selected){ return; }
                moveTarget = {targetX - center.x, targetY - center.y};
                state = MOVING;
            }

            void Enemy::setMoving(bool moving){ this->state = moving ? MOVING : IDLE; }
            bool Enemy::getMoving(){ return state == MOVING; }

            void Enemy::setAttacking(){ this->state = ATTACK; }

            bool Enemy::getSelected(){ return selected; }

            void Enemy::setTarget(Mob *&enemy){
                if(id == 1 && state == IDLE){
                    target = enemy;
                    if(collides(enemy->getHitbox())){
                        setAttacking();
                    }
                    setAttacking();
                }
                else {
                    target = enemy;
                    setAttacking();
                }
            }

            void Enemy::setSeeSoldier(Mob *sol){
                if(sol->getID() != getID()){
                    if(getID() == 1) {
                        if(state != MOVING){
                            setTarget(sol);
                        }
                    }
                    else {
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