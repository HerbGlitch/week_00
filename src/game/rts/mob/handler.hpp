#pragma once
#include <ge/ge>
#include "./group/group.hpp"
#include "mob.hpp"
#include "soldier.hpp"
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

                void spawnUnit();

                void groupMove(Group group);

            private:
                ge::QuadTree *quadTree;

                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                ui::Data *uiData;
                rts::Data *data;

                Group *mGroup;

                float speed;
                float current;
            };
        }
    }
}