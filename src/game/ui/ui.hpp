#pragma once
#include <ge.hpp>
#include <vector>
#include "../rts/mob/soldier.hpp"
#include "./selector/selector.hpp"

namespace tbyte {
    namespace rts {
        struct Surfaces;
    }
    namespace ui {
        class Handler : public ge::Surface {
        public:
            Handler(rts::Surfaces *surfaces);
            ~Handler();

            void update();
            void render();

            void updateSelector();

            void updateClick();

            bool getShouldUpdate();

            SDL_Rect getSelectedArea();

            SDL_Point movePoint;
            SDL_Rect selectedArea;

        protected:
            rts::Surfaces *surfaces;

            // std::vector<rts::MobGroup> movementGroups;

            bool shouldUpdate;

            Selector *selector;
        };
    }
}