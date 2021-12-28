#include "handler.hpp"

#include <stdint.h>
#include <stdio.h>

namespace tbyte {
    namespace rts {
        Handler::Handler(){
            surfaces = new Surfaces;
            surfaces->uiHandler = new ui::Handler(surfaces);
            surfaces->mapHandler = new map::Handler(surfaces);
            surfaces->mobHandler = new mob::Handler(surfaces, surfaces->uiHandler->getData());
        }

        Handler::~Handler(){
            delete surfaces->mapHandler;
            delete surfaces->mobHandler;
            delete surfaces->uiHandler;
            delete surfaces;
        }

        void Handler::update(){
            surfaces->mapHandler->update();
            surfaces->mobHandler->update();
            surfaces->uiHandler->update();
        }

        void Handler::render(){
            surfaces->mapHandler->render();
            surfaces->mobHandler->render();
            surfaces->uiHandler->render();
        }
    }
}