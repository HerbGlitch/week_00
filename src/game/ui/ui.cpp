#include "ui.hpp"
#include "../rts/handler.hpp"

namespace tbyte {
    namespace ui {
        Handler::Handler(rts::Surfaces *surfaces): surfaces(surfaces), selector(nullptr), shouldUpdate(false){
            data = new Data();
        }

        Handler::~Handler(){
            if(selector){ delete selector; }
            delete data;
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
                data->movePoint.x = ge::data->mouse.x;
                data->movePoint.y = ge::data->mouse.y;
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
                data->selectedArea = selector->shape();
                delete selector;
                selector = nullptr;
            }
        }

        bool Handler::getShouldUpdate(){ return shouldUpdate; }

        SDL_Rect Handler::getSelectedArea() { return data->selectedArea; }

        Data * Handler::getData() {
            return data;
        }
    }
}