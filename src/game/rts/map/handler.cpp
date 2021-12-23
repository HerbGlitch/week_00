#include "handler.hpp"
#include "../handler.hpp"
#include "../mob/mob.hpp"

namespace tbyte {
    namespace rts {
        namespace map {
            Handler::Handler(Surfaces *surfaces): surfaces(surfaces), speed(0.01f), current(0.0f) {

            }

            Handler::~Handler() { SDL_DestroyTexture(spritesheet); }

            void Handler::update() {
                if (ge::data->keyboard[SDLK_w]) {
                    current += speed;
                    if (current > 1.0f) {
                        offset.y += 1.0f;
                        current -= 1.0f;
                    }
                }
                if (ge::data->keyboard[SDLK_s]) {
                    current -= speed;
                    if (current < -1.0f) {
                        offset.y -= 1.0f;
                        current += 1.0f;
                    }
                }
                if (ge::data->keyboard[SDLK_a]) {
                    current -= speed;
                    if (current < -1.0f) {
                        offset.x -= 1.0f;
                        current += 1.0f;
                    }
                }
                if(ge::data->keyboard[SDLK_d]) {
                    current += speed;
                    if(current > 1.0f){
                        offset.x += 1.0f;
                        current -= 1.0f;
                    }
                }
            }
        }  // namespace map
    }  // namespace rts
}  // namespace tbyte