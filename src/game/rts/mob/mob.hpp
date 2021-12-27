#pragma once
#include <ge/ge>
#include <vector>
#include <queue>

namespace tbyte {
    namespace rts {
        class Mob : public ge::Sprite {
        public:
            Mob(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos): Sprite(ge::data->config.createSpriteParams(spritesheet, ge::SpriteStrs { .bounds = bounds, .scale = "scale" }, pos)){}
            virtual ~Mob(){}

            virtual void update(){}

        };

        struct MobGroup {
            unsigned int id;
            std::queue<SDL_Point> coords;
            SDL_Point current;
            std::vector<Mob *> mobs;
        };
    }
}