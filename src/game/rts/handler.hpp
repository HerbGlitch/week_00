#pragma once
#include <ge/ge>
#include "data.hpp"
#include "./mob/handler.hpp"
#include "./map/handler.hpp"
#include "../ui/handler.hpp"

namespace tbyte {
    namespace rts {
        struct Surfaces {
            map::Handler *mapHandler;
            mob::Handler *mobHandler;
            ui::Handler *uiHandler;
        };

        class Handler : public ge::State {
        public:
            Handler();
            ~Handler();

            void update();
            void render();

        private:
            Surfaces *surfaces;
            Data *data;
        };
    }
}