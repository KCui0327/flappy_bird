#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"

GameState::GameState(GameDataRef data) : _data(data) {

}

void GameState::init() {
    std::cout << "Game State" << std::endl;
    _data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    _background.setTexture(this->_data->assets.getTexture("Game Background"));
}

void GameState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
    }
}

void GameState::update(float delta) {
}

void GameState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.display();
}

