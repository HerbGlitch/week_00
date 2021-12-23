#pragma once
#include <ge/ge>

namespace tbyte {
    namespace rts {
        struct Surfaces;
        namespace map {
            class Handler : public ge::Surface {
            public:
                Handler(Surfaces *surfaces);
                ~Handler();

                void update();

            private:
                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                float speed;
                float current;
            };
        }
    }
}