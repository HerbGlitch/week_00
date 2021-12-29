#include "handler.hpp"
#include "../rts/handler.hpp"
#include <iostream>

namespace tbyte {
    namespace ui {
        Handler::Handler(rts::Surfaces *surfaces, rts::Data *rtsData): surfaces(surfaces), rtsData(rtsData), selector(nullptr){
            offset = rtsData->offset;
            data = new Data { { -1, -1, 0, 0 }, { 0, 0, false, false } };
        }

        Handler::~Handler(){
            if(selector){ delete selector; }
            delete data;
        }

        void Handler::update(){
            data->mouse.x = ge::data->mouse.x - offset->x;
            data->mouse.y = ge::data->mouse.y - offset->y;
            updateClick();
            updateSelector();
        }

        void Handler::render(){
            if(selector){ selector->render(); }
        }

        void Handler::updateClick() {
            if(ge::data->mouse[SDL_BUTTON_RIGHT] == ge::Mouse::RELEASED){
                data->mouse.rightReleased = true;
                return;
            }
            data->mouse.rightReleased = false;
        }

        void Handler::updateSelector(){
            if(!selector){
                if(ge::data->mouse[SDL_BUTTON_LEFT] == ge::Mouse::PRESSED){
                    selector = new Selector(rtsData->offset);
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

        SDL_Rect Handler::getSelectedArea() {
            SDL_Rect selected = data->selectedArea;
            selected.x -= offset->x;
            selected.y -= offset->y;
            return selected; 
        }

        Data *Handler::getData(){ return data; }
    }
}