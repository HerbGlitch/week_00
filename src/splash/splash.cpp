#include "splash.hpp"

namespace tbyte{
    Splash::Splash(){
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        SDL_Texture *tbyteSheet;
        ge::data->config.get(GE_VAR_STR(tbyteSheet));

        logo = new ge::Sprite(ge::data->config.createSpriteParams(tbyteSheet, ge::SpriteStrs { .bounds = "tbyteBounds", .scale = "scale" }));
        // logo = new ge::Sprite(tbyteSheet, tbyteBounds, ge::data->windowSize.w / 2 - (tbyteBounds.w * scale / 2), ge::data->windowSize.h / 2 - (tbyteBounds.h * scale / 2));
        // logo->setScale(scale);

        add(logo);
    }

    Splash::~Splash(){}

    void Splash::update(){
        // if (ge::data->mouse[SDL_BUTTON_LEFT]) {
        //     ge::data->state.add(tbyte::Game, true);
        // }
    }
}
