#pragma once
#include <ge/ge>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Soldier : public Mob {
            public:
                Soldier(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale);
                ~Soldier();

                void update();

                void startMove(int targetX, int targetY);

                void setMoving(bool moving);
                bool getMoving();
                void setSelected(bool val);

                bool getSelected();

            private:
                SDL_Point moveTarget;

                bool selected;
                bool moving;
            };
        }
    }
}