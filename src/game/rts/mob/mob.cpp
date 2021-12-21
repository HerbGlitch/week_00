#include "entity.hpp"

namespace tbyte {
    namespace rts {
        Mob::Mob(SDL_Texture *spritesheet, int id, int maxHealth, int health, int xp, int range): id(id), maxHealth(maxHealth), health(health) xp(xp), range(range) {
            ge::Entity(spritesheet, ge::EntityStrs {bounds = "allyBounds", .scale = "scale"}});
        }

        Mob::~Mob(){

        }

        void Mob::update(){
            
        }
    }
}