#pragma once
#include <ge.hpp>

namespace tbyte {
    class Splash : public ge::State {
    public:
        Splash();
        ~Splash();

        void update();
        void render();

    private:
        SDL_Texture *tbyteSheet;

        ge::Sprite *logo;
    };
}