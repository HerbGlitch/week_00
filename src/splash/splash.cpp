#include "splash.hpp"

namespace tbyte{
    Splash::Splash(){
        ge::data->config.load("./res/config/defaults.config");
        ge::data->config.setGroup("");

        SDL_Rect tbyteBounds;
        int scale;

        ge::data->config.get(GE_VAR_STR(tbyteSheet));
        ge::data->config.get(GE_VAR_STR(tbyteBounds));
        ge::data->config.get(GE_VAR_STR(scale));

        // logo = new ge::Sprite(tbyteSheet, tbyteBounds, ge::data->windowSize.w / 2 - (tbyteBounds.w * scale / 2), 200 );
        logo->setScale(scale);
    }
    Splash::~Splash(){}
    
    void Splash::update(){}
    void Splash::render(){
        logo->draw();
    }
}
