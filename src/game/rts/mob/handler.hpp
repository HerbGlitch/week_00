#pragma once
#include <ge.hpp>
#include "mob.hpp"
#include "soldier.hpp"

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

            private:
                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                float speed;
                float current;
            };
        }
    }
}