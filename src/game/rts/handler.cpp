#include "handler.hpp"

namespace tbyte {
    namespace rts {
        Handler::Handler(){
            mobHandler = new mob::Handler();
        }

        Handler::~Handler(){
            delete mobHandler;
        }

        void Handler::update(){
            mobHandler->update();
        }

        void Handler::render(){
            mobHandler->render();
        }
    }
}