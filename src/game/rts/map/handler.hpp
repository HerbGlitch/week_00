#pragma once
#include <ge/ge>
#include "../data.hpp"

namespace tbyte {
    namespace rts {
        struct Surfaces;
        namespace map {
            class Handler : public ge::Surface {
            public:
                Handler(Surfaces *surfaces, rts::Data *data);
                ~Handler();

                void update();

            private:
                rts::Data *data;
                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                float speed;
                float currentX, currentY;
            };
        }
    }
}