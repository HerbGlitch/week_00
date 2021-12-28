#pragma once
#include <SDL.h>

namespace tbyte {
    namespace ui {
        struct Data {
            SDL_Rect selectedArea;
            struct {
                int x, y;
                bool rightReleased, leftReleased;
            } mouse;
        };
    }
}