#pragma once
#include <ge/ge>
#include "group.hpp"
#include "mob.hpp"
#include "soldier.hpp"
#include "../../ui/data.hpp"

namespace tbyte {
    namespace rts {
        struct Surfaces;
        namespace mob {
            class Handler : public ge::Grid {
            public:
                Handler(Surfaces *surfaces, ui::Data *uiData);
                ~Handler();

                void update();

                void spawnUnit();

                void groupMove(Group group);

            private:
                SDL_Texture *spritesheet;
                Surfaces *surfaces;

                ui::Data *uiData;

                Group *mGroup;

                float speed;
                float current;
            };
        }
    }
}