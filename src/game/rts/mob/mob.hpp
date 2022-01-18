#pragma once
#include <ge/ge>
#include <vector>
#include <queue>

namespace tbyte {
    namespace rts {
        enum States {
            IDLE,
            MOVING,
            ATTACK,
        };

        class Mob : public ge::Sprite {
        public:
            Mob(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale, int id, int health): Sprite(sprite, scale, pos), moveTarget({0, 0}), id(id), health(health), state(IDLE), canAttack(true), timeKeep(0.0f){
                hitBox = new GE_Bounds();
                vision = new SDL_Rect({-50, -50, 100, 100});
            }
            virtual ~Mob(){}

            virtual void update(){}

            int getID(){ return id; }
            int getHealth(){ return health; }

            virtual void attack(Mob *target, int damage){}
            virtual bool getAttacked(Mob *target, int damage){ return false; }

            SDL_Rect getVision(){ return SDL_Rect({ getBounds().x + vision->x, getBounds().y + vision->y, getBounds().w + vision->w, getBounds().h + vision->h }); }
            SDL_Rect *getHitbox(){ 
                hitBox->x = getBounds().x - 5;
                hitBox->y = getBounds().y - 5;
                hitBox->w = getBounds().w + 10;
                hitBox->h = getBounds().h + 10;
                return hitBox;
            }

            SDL_Point moveTarget;

            Mob *target;

            SDL_Rect *vision;

            GE_Bounds *hitBox;

            States state;

            int id, health;

            bool canAttack;

            float timeKeep;
        };
    }
}