#pragma once
#include <ge.hpp>

namespace tbyte {
    class Game : public ge::State {
    public:
        Game();
        ~Game();

        void update();
        void render();

    };
}