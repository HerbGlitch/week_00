#include "handler.hpp"

#include <stdint.h>
#include <stdio.h>

namespace tbyte {
    namespace rts {
        Handler::Handler(){
            surfaces->mapHandler = map::Handler(surfaces);
            surfaces->mobHandler = mob::Handler(surfaces);
            surfaces->uihandler = ui::Handler(surfaces);
        }

        Handler::~Handler(){
        }

        void Handler::update(){
            for(int i = 0; i < 3; i++){ surfaces[i]->update(); }
        }

        void Handler::render(){
            for(int i = 0; i < 3; i++){ surfaces[i]->render(); }
        }
    }
}