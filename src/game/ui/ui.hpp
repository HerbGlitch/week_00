#pragma once
#include <ge.hpp>
#include <vector>
#include "../rts/mob/soldier.hpp"
#include "./selector/selector.hpp"

namespace tbyte {
    namespace ui {
        class Handler : public ge::Surface {
        public:
            Handler();
            ~Handler();

            void update();
            void render();

            void updateSelector();

            void updateClick();

            bool getShouldUpdate();

            SDL_Point movePoint;
            SDL_Rect selectedArea;

        protected:
            std::vector<rts::MobGroup> movementGroups;

            bool shouldUpdate;

            Selector *selector;
        };
    }
}