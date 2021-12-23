#pragma once
#include <ge/ge>

#include "rts/handler.hpp"

namespace tbyte {
    class Game : public ge::State {
    public:
        Game();
        ~Game();

        void update();
        void render();

    private:
        rts::Handler *rtsHandler;
    };
}