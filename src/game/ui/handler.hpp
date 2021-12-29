#pragma once
#include <ge/ge>
#include <vector>
#include "../rts/mob/soldier.hpp"
#include "./selector/selector.hpp"
#include "data.hpp"
#include "../rts/data.hpp"

namespace tbyte {
    namespace rts { struct Surfaces; }

    namespace ui {
        class Handler : public ge::Surface {
        public:
            Handler(rts::Surfaces *surfaces, rts::Data *rtsData);
            ~Handler();

            void update();
            void render();

            void updateSelector();

            void updateClick();

            bool getShouldUpdate();

            SDL_Rect getSelectedArea();

            Data *getData();

        protected:
            rts::Surfaces *surfaces;

            Selector *selector;

            Data *data;
            rts::Data *rtsData;
        };
    }
}