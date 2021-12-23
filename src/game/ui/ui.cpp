#include "ui.hpp"
#include "../rts/handler.hpp"

namespace tbyte {
    namespace ui {
        Handler::Handler(rts::Surfaces *surfaces): surfaces(surfaces), selector(nullptr), shouldUpdate(false){}

        Handler::~Handler(){
            if(selector){ delete selector; }
        }

        void Handler::update(){
            updateClick();
            updateSelector();
        }

        void Handler::render(){
            if(selector){ selector->render(); }
        }

        void Handler::updateClick() {
            if(ge::data->mouse[SDL_BUTTON_RIGHT] == ge::Mouse::RELEASED){
                movePoint.x = ge::data->mouse.x;
                movePoint.y = ge::data->mouse.y;
                shouldUpdate = true;
                return;
            }
            shouldUpdate = false;
        }

        void Handler::updateSelector(){
            if(!selector){
                if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){ selector = new Selector(); }
                return;
            }

            if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){
                selector->update();
                return;
            }

            if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::RELEASED){
                selectedArea = selector->shape();
                delete selector;
                selector = nullptr;
            }
        }

        bool Handler::getShouldUpdate(){ return shouldUpdate; }

        SDL_Rect Handler::getSelectedArea() { return selectedArea; }
    }
}