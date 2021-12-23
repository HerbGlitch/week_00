#pragma once
#include <ge/ge>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Soldier : public Mob {
            public:
                Soldier(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos);
                ~Soldier();

                void update();

                void startMove(int targetX, int targetY);

                void setSelected(bool val);

            private:
                bool moving;
                SDL_Point target;
                bool selected;
            };
        }
    }
}