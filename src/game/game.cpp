#include "game.hpp"

namespace tbyte {
    Game::Game(){
        rtsHandler = new rts::Handler();
    }

    Game::~Game(){
        delete rtsHandler;
    }

    void Game::update(){
        rtsHandler->update();
    }

    void Game::render(){
        rtsHandler->render();
    }
}