#pragma once
#include <ge/ge>
#include <vector>
#include <queue>

namespace tbyte {
    namespace rts {
        class Mob : public ge::Sprite {
        public:
            Mob(GE_Sprite *sprite, SDL_Point pos, GE_Scale &scale): Sprite(sprite, scale, pos){}
            virtual ~Mob(){}

            virtual void update(){}
        };
    }
}