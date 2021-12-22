#include "game.hpp"

namespace tbyte {
    Game::Game(){
        ge::data->config.load("./res/config/defaults.config");


        rtsHandler = new rts::Handler();
    }

    Game::~Game(){
        // ge::data->config.unload("./res/config/defaults.config");
        delete rtsHandler;
    }

    void Game::update(){
        rtsHandler->update();
    }

    void Game::render(){
        rtsHandler->render();
    }
}