#pragma once
#include <ge/ge>
#include "mob.hpp"
#include "soldier.hpp"
#include "../../ui/data.hpp"
#include <vector>
#include <math.h>

namespace tbyte {
    namespace rts {
        struct Surfaces;
        namespace mob {
            class Handler : public ge::Grid {
            public:
                Handler(Surfaces *surfaces);
                ~Handler();

                void update();

                void spawnUnit();

                void getcoordsFromGroup();

                SDL_Point getAvailableSpace(int numUnits);

            private:
                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                MobGroup *mGroup;

                float speed;
                float current;
            };
        }
    }
}