#pragma once
#include <ge.hpp>
#include "./mob/handler.hpp"

namespace tbyte {
    namespace rts {
        class Handler : ge::State {
        public:
            Handler();
            ~Handler();

            void update :

        private:
            MobHandler *mobHandler;
        }
    }
}