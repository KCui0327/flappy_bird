#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "GameOverState.h"

GameOverState::GameOverState(GameDataRef data) : _data(data) {

}

void GameOverState::init() {
    std::cout << "Game State" << std::endl;
    _data->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.getTexture("Game Over Background"));
}

void GameOverState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
    }
}

void GameOverState::update(float delta) {
}

void GameOverState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}

