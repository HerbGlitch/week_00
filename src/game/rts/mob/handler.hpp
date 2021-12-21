#pragma once
#include <ge.hpp>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Handler : public ge::State {
            public:
                Handler();
                ~Handler();

                void update();

            private:
                SDL_Texture *spritesheet;
            };
        }
    }
}