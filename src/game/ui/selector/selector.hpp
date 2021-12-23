#pragma once
#include <ge/ge>

namespace tbyte {
    namespace ui {
        class Selector {
        public:
            Selector();

            void update();
            void render();

            SDL_Rect shape();

        protected:
            SDL_Rect selection;
            Sint32 x, y;
        };
    }
}