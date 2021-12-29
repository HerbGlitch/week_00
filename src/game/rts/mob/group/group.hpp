#pragma once
#include <ge/ge>
#include <vector>
#include <queue>
#include "../mob.hpp"
#include "../soldier.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            class Group {
            public:
                Group();

                void update();

                void addMob(Mob *mob);

                void addCoord(SDL_Point pos);

                bool empty();

                std::vector<Mob *> &getMobs(){ return mobs; }

                uint32_t id;

            private:
                std::queue<SDL_Point> coords;
                std::vector<Mob *> mobs;
                SDL_Point current;
                bool moving;
            };
        }
    }
}