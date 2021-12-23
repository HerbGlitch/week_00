#pragma once
#include <ge.hpp>

namespace tbyte {
    namespace rts {
        namespace map {
            class Handler : public ge::Surface {
            public:
                Handler(rts::Surfaces states);
                ~Handler();

                void update();

            private:
                SDL_Texture *spritesheet;
                ge::Surface states;

                float speed;
                float current;
            };
        }
    }
}