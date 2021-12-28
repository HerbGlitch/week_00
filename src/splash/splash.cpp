#include "splash.hpp"

namespace tbyte{
    Splash::Splash(){
        ge::data->config.load("./res/config/splash.config");
        ge::data->config.setGroup("");

        GE_Sprite *tbyteLogo;
        ge::data->config.get(GE_VAR_STR(tbyteLogo));

        logo = new ge::Sprite(tbyteLogo);
        logo->setPos(ge::data->windowSize.w / 2 - logo->getCenter().x, ge::data->windowSize.h / 2 - logo->getCenter().y);

        add(logo);
    }

    Splash::~Splash(){}

    void Splash::update(){
        // if (ge::data->mouse[SDL_BUTTON_LEFT]) {
        //     ge::data->state.add(tbyte::Game, true);
        // }
    }
}
