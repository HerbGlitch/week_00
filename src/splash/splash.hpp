#pragma once
#include <ge/ge>

namespace tbyte {
    class Splash : public ge::Surface {
    public:
        Splash();
        ~Splash();

        void update();

    private:
        SDL_Texture *tbyteSheet;

        ge::Sprite *logo;
    };
}