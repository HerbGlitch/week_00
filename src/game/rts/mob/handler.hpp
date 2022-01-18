#pragma once
#include <ge/ge>
#include "./group/group.hpp"
#include "mob.hpp"
#include "soldier.hpp"
#include "enemy.hpp"
#include "../../ui/data.hpp"
#include "../data.hpp"

namespace tbyte {
    namespace rts {
        struct Surfaces;
        namespace mob {
            class Handler : public ge::Surface {
            public:
                Handler(Surfaces *surfaces, rts::Data *data, ui::Data *uiData);
                ~Handler();

                void update();
                void render();

            private:
                void refreshQuadTree();

                void check();

                bool checkVision(Mob *mob);
                void checkCollision(Mob *mob);

                void groupMove(Group group);

                void spawnUnit();

                ge::QuadTree *quadTree;

                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                ui::Data *uiData;
                rts::Data *data;

                Group *mGroup;
                GE_Bounds bounds;

                float speed;
                float current;
            };
        }
    }
}