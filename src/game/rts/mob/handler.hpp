#pragma once
#include <ge.hpp>
#include "mob.hpp"
#include "soldier.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Handler : public ge::Grid {
            public:
                Handler(ge::Surface **states);
                ~Handler();

                void update();

                void spawnUnit();

            private:
                SDL_Texture *spritesheet;
                ge::Surface **states;

                float speed;
                float current;
            };
        }
    }
}