#include "handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(){
                ge::data->config.load("./res/config/defaults.config");
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                add(new Mob(spritesheet, 1, 100, 100, 0, 32));
            }

            Handler::~Handler(){
                SDL_DestroyTexture(spritesheet);
            }

            void Handler::update() {
                for(ge::Object *object : hTypes){
                    ((Mob *)object)->move(0.01f, 0.00f);
                }
            }
        }
    }
}