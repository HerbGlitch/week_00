#include "handler.hpp"

#include "../mob/mob.hpp"

namespace tbyte {
    namespace rts {
        namespace map {
            Handler::Handler(rts::Surfaces states): states(states), speed(0.01f), current(0.0f) {
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                ge::ColorGrid tempMap;
                ge::data->config.get(GE_VAR_STR(tempMap));

                int scale;
                ge::data->config.get(GE_VAR_STR(scale));

                for (int y = 0; y < tempMap.h; y++) {
                    for (int x = 0; x < tempMap.w; x++) {
                        unsigned int c = tempMap.colors[x + (y * tempMap.w)];

                        if (c == 0xff0000) {
                            add(new Mob(spritesheet, "wallBounds", SDL_Point{x * 32 * scale, y * 32 * scale}));
                            continue;
                        }
                        if (c == 0x00ff00) {
                            add(new Mob(spritesheet, "pathBounds", SDL_Point{x * 32 * scale, y * 32 * scale}));
                            continue;
                        }
                        if (c == 0x0000ff) {
                            add(new Mob(spritesheet, "stairsBounds", SDL_Point{x * 32 * scale, y * 32 * scale}));
                        }
                    }
                }
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