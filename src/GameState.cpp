#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"


GameState::GameState(GameDataRef data) : _data(data) {

}

void GameState::init() {
    std::cout << "Game State" << std::endl;
    _data->assets.loadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
    _data->assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
    _data->assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
    _data->assets.loadTexture("Land", LAND_FILEPATH);
    _data->assets.loadTexture("Bird1", BIRD_FRAME_1_FILEPATH);
    _data->assets.loadTexture("Bird2", BIRD_FRAME_2_FILEPATH);
    _data->assets.loadTexture("Bird3", BIRD_FRAME_3_FILEPATH);
    _data->assets.loadTexture("Bird4", BIRD_FRAME_4_FILEPATH);


    pipe = new Pipe(_data);
    land = new Land(_data);
    bird = new Bird(_data);

    _background.setTexture(this->_data->assets.getTexture("Game Background"));
}

void GameState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
        if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
            bird->tap();
        }

    }
}

void GameState::update(float delta) {
    pipe->movePipes(delta);
    land->moveLand(delta);
    if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
        pipe->randomizePipeOffset();
        pipe->spawnInvisiblePipe();
        pipe->spawnBottomPipe();
        pipe->spawnTopPipe();
        clock.restart();
    }
    bird->animate(delta);
    bird->update(delta);
}

void GameState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    pipe->drawPipes();
    land->drawLand();
    bird->draw();
    _data->window.display();
}

