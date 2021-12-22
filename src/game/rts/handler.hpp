#pragma once
#include <ge.hpp>
#include "./mob/handler.hpp"
#include "./map/handler.hpp"
#include "../ui/ui.hpp"

namespace tbyte {
    namespace rts {
        class Handler : public ge::State {
        public:
            Handler();
            ~Handler();

            void update();
            void render();

        private:
            ge::Surface *states[3];
        };
    }
}