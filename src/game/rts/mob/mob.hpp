#pragma once
#include <ge.hpp>

namespace tbyte {
    namespace rts {
        class Mob : public ge::Entity {
        public:
            Mob(SDL_Texture *spritesheet, int id, int maxHealth, int health, int xp, int range): ge::Entity(spritesheet, ge::EntityStrs {.bounds = "allyBounds", .scale = "scale"}){}
            virtual ~Mob(){}

            virtual void update(){}

        protected:
            int id, maxHealth, health, xp, range; 
        };
    }
}