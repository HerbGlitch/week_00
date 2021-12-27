#pragma once
#include <ge/ge>
#include "mob.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Soldier : public Mob {
            public:
                Soldier(SDL_Texture *spritesheet, const char *bounds, SDL_Point pos);
                ~Soldier();

                void update();

                void startMove(int targetX, int targetY);

                void setMoving(bool newMoving);

                void setSelected(bool val);

                bool getSelected();

                bool selected;
                bool moving;
            
            private:
                SDL_Point moveTarget;
                SDL_Rect idleBounds; 
                SDL_Rect selectedBounds; 
            };
        }
    }
}