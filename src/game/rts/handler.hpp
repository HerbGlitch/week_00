#pragma once
#include <ge.hpp>
#include "./mob/handler.hpp"
#include "./map/handler.hpp"
#include "../ui/ui.hpp"

namespace tbyte {
    namespace rts {
        public struct Surfaces {
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
            Surfaces surfaces;
        };
    }
}