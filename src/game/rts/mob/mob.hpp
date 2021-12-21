#pragma once
#include <ge.hpp>

namespace tbyte {
    namespace rts {
        class Mob : ge::Entity {
        public:
            Mob(SDL_Texture *spritesheet, int id, int maxHealth, int health, int xp, int range);
            virtual ~Mob();

            void update();
        protected:
            int id, maxHealth, health, xp, range;            
        }
    }
}