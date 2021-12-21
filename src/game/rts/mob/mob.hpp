#pragma once
#include <ge.hpp>

namespace tbyte {
    namespace rts {
        class Mob : public ge::Entity {
        public:
            Mob(SDL_Texture *spritesheet, const char *bounds, int id, int maxHealth, int health, int xp, int range, SDL_Point pos): ge::Entity(spritesheet, ge::EntityStrs { .bounds = bounds, .scale = "scale" }, pos){}
            virtual ~Mob(){}

            virtual void update(){}

        protected:
            int id, maxHealth, health, xp, range; 
        };
    }
}