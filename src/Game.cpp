#include "Game.h"
#include "SplashState.h"
#include <stdlib.h>
#include <time.h>

Game::Game(int width, int height, std::string title) {
    srand(time(nullptr));
    _data->window.create(
        sf::VideoMode(width, height),
        title,
        sf::Style::Close | sf::Style::Titlebar
    );

    _data->machine.addState(StateRef(new SplashState(this->_data)));

    this->run();
}

void Game::run() {
    float newTime, frameTime, interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->_data->window.isOpen()) {
        this->_data->machine.processStateChanges();
        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if (frameTime > 0.25f) frameTime = 0.25f;
        currentTime = newTime;
        accumulator += frameTime;
        while (accumulator >= delta) {
            this->_data->machine.getActiveState()->handleInput();
            this->_data->machine.getActiveState()->update(delta);
            accumulator -= delta;
        }
        interpolation = accumulator / delta;
        this->_data->machine.getActiveState()->draw(interpolation);
    }
}