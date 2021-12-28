#include "ui.hpp"
#include "../rts/handler.hpp"

namespace tbyte {
    namespace ui {
        Handler::Handler(rts::Surfaces *surfaces): surfaces(surfaces), selector(nullptr){
            data = new Data { { -1, -1, 0, 0 }, { 0, 0, false, false } };
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
                data->mouse.x = ge::data->mouse.x;
                data->mouse.y = ge::data->mouse.y;
                data->mouse.rightReleased = true;
                return;
            }
            data->mouse.rightReleased = false;
        }

        void Handler::updateSelector(){
            if(!selector){
                if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){
                    selector = new Selector();
                    return;
                }
                data->mouse.leftReleased = false;
                return;
            }

            if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){
                selector->update();
                data->mouse.leftReleased = false;
                return;
            }

            if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::RELEASED){
                data->selectedArea = selector->shape();
                data->mouse.leftReleased = true;
                delete selector;
                selector = nullptr;
                return;
            }
            
            data->mouse.leftReleased = false;
        }

        bool Handler::getShouldUpdate(){ return data->mouse.leftReleased; }

        SDL_Rect Handler::getSelectedArea() { return data->selectedArea; }

        Data *Handler::getData(){ return data; }
    }
}