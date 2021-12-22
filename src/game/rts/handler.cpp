#include "handler.hpp"

#include <stdint.h>
#include <stdio.h>

namespace tbyte {
    namespace rts {
        Handler::Handler(){
            states[0] = new map::Handler(states);
            states[1] = new mob::Handler(states);
            states[2] = new ui::Handler();
        }

        Handler::~Handler(){
            for(int i = 0; i < 3; i++){ delete states[i]; }
        }

        void Handler::update(){
            for(int i = 0; i < 3; i++){ states[i]->update(); }
        }

        void Handler::render(){
            for(int i = 0; i < 3; i++){ states[i]->render(); }
        }
    }
}