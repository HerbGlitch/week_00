#pragma once
#include <ge.hpp>
#include <vector>

namespace tbyte {
    namespace rts {
        class Mob : public ge::Sprite {
        public:
            Mob(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos): Sprite(ge::data->config.createSpriteParams(spritesheet, ge::SpriteStrs { .bounds = bounds, .scale = "scale" }, pos)){}
            virtual ~Mob(){}

            virtual void update(){}

        };

        typedef struct MobGroup {
            unsigned int id;
            std::vector<Mob *> mobs;
        } MobGroup;
    }
}