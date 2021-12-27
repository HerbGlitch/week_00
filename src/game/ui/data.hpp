#pragma once
#include <SDL.h>

namespace tbyte {
    namespace ui {
        struct Data {
            SDL_Rect selectedArea;
            SDL_Point movePoint; 
        };
    }
}