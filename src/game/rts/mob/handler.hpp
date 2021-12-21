#pragma once
#include <ge.hpp>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        class MobHandler {
        public:
            MobHandler();
            ~MobHandler();

            void update();
        private:
            SDL_Texture *spritsheet;

        }
    }
}