#include "selector.hpp"

namespace tbyte {
    namespace ui {
        Selector::Selector(): selection({ge::data->mouse.x, ge::data->mouse.y, 0, 0}), x(ge::data->mouse.x), y(ge::data->mouse.y){}

        void Selector::update(){
            selection.x = (x < ge::data->mouse.x)? x : ge::data->mouse.x;
            selection.y = (y < ge::data->mouse.y)? y : ge::data->mouse.y;
            selection.w = (x < ge::data->mouse.x)? ge::data->mouse.x - x : x - ge::data->mouse.x;
            selection.h = (y < ge::data->mouse.y)? ge::data->mouse.y - y : y - ge::data->mouse.y;
        }

        void Selector::render(){
            SDL_SetRenderDrawColor(ge::data->renderer, 0x00, 0xff, 0x00, 0xff);
            SDL_RenderDrawRect(ge::data->renderer, &selection);
        }

        SDL_Rect Selector::shape(){ return selection; }
    }
}