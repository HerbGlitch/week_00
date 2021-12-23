#pragma once
#include <ge.hpp>
#include "mob.hpp"
#include "soldier.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Handler : public ge::Grid {
            public:
                Handler(rts::Surfaces surfaces);
                ~Handler();

                void update();

                void spawnUnit();

            private:
                SDL_Texture *spritesheet;
                rts::Surfaces **states;

                float speed;
                float current;
            };
        }
    }
}