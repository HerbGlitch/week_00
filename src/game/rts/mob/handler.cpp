#include "handler.hpp"

namespace tbyte {
    namespace rts {
        MobHandler::MobHandler(){
            ge::data->config.load("./res/config/defaults.config");
            ge::data->config.setGroup("");

            ge::data->config.(SDL_VAR_GET("tempSheet"))

            new Mob(spritesheet, 1, 100, 100, 0, 32);
        }
        
        MobHandler::~MobHandler(){
            SDL_DestroyTexture(spritsheet);
        }
    }
}