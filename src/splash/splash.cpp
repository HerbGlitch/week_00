#include "splash.hpp"

namespace tbyte{
    Splash::Splash(){
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        SDL_Texture *tbyteSheet;
        ge::data->config.get(GE_VAR_STR(tbyteSheet));

        logo = new ge::Entity(tbyteSheet, ge::EntityStrs { .bounds = "tbyteBounds", .scale = "scale" });
        // logo = new ge::Sprite(tbyteSheet, tbyteBounds, ge::data->windowSize.w / 2 - (tbyteBounds.w * scale / 2), ge::data->windowSize.h / 2 - (tbyteBounds.h * scale / 2));
        // logo->setScale(scale);

        add((ge::Object *)logo);
    }

    Splash::~Splash(){}

    void Splash::update(){
        //TODO: change after x seconds, and if ___.config is created, allow skip by esc press
    }
}
