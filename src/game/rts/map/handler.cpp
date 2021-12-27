#include "handler.hpp"
#include "../handler.hpp"
#include "../mob/mob.hpp"

namespace tbyte {
    namespace rts {
        namespace map {
            Handler::Handler(Surfaces *surfaces): surfaces(surfaces), speed(0.04f), currentX(0.0f), currentY(0.0f) {
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                ge::ColorGrid *tempMap;
                ge::data->config.get(GE_VAR_STR(tempMap));

                int scale;
                ge::data->config.get(GE_VAR_STR(scale));

                for (int y = 0; y < tempMap->h; y++) {
                    for (int x = 0; x < tempMap->w; x++) {
                        unsigned int c = tempMap->colors[x + (y * tempMap->w)];

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

            Handler::~Handler() { 
                SDL_DestroyTexture(spritesheet); 
            }

            void Handler::update() {
                if (ge::data->keyboard.getPress(SDLK_w)) {
                    currentY += speed;
                    if (currentY > 1.0f) {
                        offset.y += 1.0f;
                        currentY -= 1.0f;
                    }
                }
                if (ge::data->keyboard.getPress(SDLK_s)) {
                    currentY -= speed;
                    if (currentY < -1.0f) {
                        offset.y -= 1.0f;
                        currentY += 1.0f;
                    }
                }
                if (ge::data->keyboard.getPress(SDLK_d)) {
                    currentX -= speed;
                    if (currentX < -1.0f) {
                        offset.x -= 1.0f;
                        currentX += 1.0f;
                    }
                }
                if(ge::data->keyboard.getPress(SDLK_a)) {
                    currentX += speed;
                    if(currentX > 1.0f){
                        offset.x += 1.0f;
                        currentX -= 1.0f;
                    }
                }
            }
        }  // namespace map
    }  // namespace rts
}  // namespace tbyte