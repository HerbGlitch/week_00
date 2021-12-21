#include "handler.hpp"

namespace tbyte {
    namespace rts {
        namespace mob {
            Handler::Handler(): speed(0.007f), current(0.0f){
                ge::data->config.load("./res/config/defaults.config");
                ge::data->config.setGroup("");

                ge::data->config.get(GE_VAR_STR(spritesheet));

                ge::ColorGrid tempMap;
                ge::data->config.get(GE_VAR_STR(tempMap));

                int scale;
                ge::data->config.get(GE_VAR_STR(scale));

                for(int y = 0; y < tempMap.h; y++){
                    for(int x = 0; x < tempMap.w; x++){
                        unsigned int c = tempMap.colors[x + (y * tempMap.w)];

                        if(c == 0xff0000){ printf("r");}
                        else if(c == 0x00ff00){ printf("g"); }
                        else if(c == 0x0000ff){ printf("b"); }
                        else { printf(" "); }

                        if(c == 0xff0000){
                            add(new Mob(spritesheet, "wallBounds", 1, 100, 100, 0, 32, SDL_Point { x * 32 * scale, y * 32 * scale }));
                            continue;
                        }
                        if(c == 0x00ff00){
                            add(new Mob(spritesheet, "pathBounds", 1, 100, 100, 0, 32, SDL_Point { x * 32 * scale, y * 32 * scale }));
                            continue;
                        }
                        if(c == 0x0000ff){
                            add(new Mob(spritesheet, "stairsBounds", 1, 100, 100, 0, 32, SDL_Point { x * 32 * scale, y * 32 * scale }));
                        }
                    }
                    printf("\n");
                }
            }

            Handler::~Handler(){
                SDL_DestroyTexture(spritesheet);
            }

            void Handler::update() {
                current += speed;
                if(current > 1.0f){
                    offset.y -= 1.0f;
                    current -= 1.0f;
                }
            }
        }
    }
}