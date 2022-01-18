#pragma once
#include <ge/ge>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {

            class Enemy : public Mob {
            public:
                Enemy(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale, int id);
                ~Enemy();

                void update();

                void startMove(int targetX, int targetY);

                void setMoving(bool moving);
                bool getMoving();

                void setAttacking();
                bool getAttacking();

                void setSelected(bool selected);

                void setTarget(Mob *&enemy);

                void setSeeSoldier(Mob *sol);

                bool getSelected();

                void attack(Mob *target, int damage);
                bool getAttacked(Mob *target, int damage);


            private:

                bool selected;
            };
        }
    }
}