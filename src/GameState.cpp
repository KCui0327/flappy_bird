#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "GameState.h"
#include "GameOverState.h"


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
    _data->assets.loadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
    _data->assets.loadFont("Flappy Font", FLAPPY_FONT_FILEPATH);

    pipe = new Pipe(_data);
    land = new Land(_data);
    bird = new Bird(_data);
    flash = new Flash(_data);
    hud = new HUD(_data);

    _background.setTexture(this->_data->assets.getTexture("Game Background"));

    _score = 0;
    hud->updateScore(_score);

    _gameState = GameStates::eReady;
}

void GameState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
        if (_data->input.isSpriteClicked(_background, sf::Mouse::Left, _data->window)) {
            if (GameStates::eGameOver != _gameState) {
                _gameState = GameStates::ePlaying;
                bird->tap();
            }
        }

    }
}

void GameState::update(float delta) {
    if (GameStates::eGameOver != _gameState) {
        bird->animate(delta);
        land->moveLand(delta);
    }

    if (GameStates::ePlaying == _gameState) {
        pipe->movePipes(delta);
        if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
            pipe->randomizePipeOffset();
            pipe->spawnInvisiblePipe();
            pipe->spawnBottomPipe();
            pipe->spawnTopPipe();
            pipe->spawnScoringPipe();
            clock.restart();
        }
        bird->update(delta);

        std::vector<sf::Sprite> landSprites = land->getSprites();
        for (int i = 0; i < landSprites.size(); i++) {
            if (collision.checkSpriteCollision(bird->getSprite(), 0.7f, landSprites.at(i), 1.0f)) {
                _gameState = GameStates::eGameOver;
                clock.restart();
            }
        }

        std::vector<sf::Sprite> pipeSprites = pipe->getSprites();
        for (int i = 0; i < pipeSprites.size(); i++) {
            if (collision.checkSpriteCollision(bird->getSprite(), 0.625f, pipeSprites.at(i), 1.0f)) {
                _gameState = GameStates::eGameOver;
                clock.restart();
            }
        }

        std::vector<sf::Sprite> &scoringSprites = pipe->getScoringSprites();
        for (int i = 0; i < scoringSprites.size(); i++) {
            if (collision.checkSpriteCollision(bird->getSprite(), 0.625f, scoringSprites.at(i), 1.0f)) {
                _score++;
                hud->updateScore(_score);
                scoringSprites.erase(scoringSprites.begin() + i);
            }
        }
    }

    if (GameStates::eGameOver == _gameState) {
        flash->show(delta);
    }

    if (GameStates::eGameOver == _gameState) {
        flash->show(delta);
        if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
            _data->machine.addState(StateRef(new GameOverState(_data, _score)), true);
        }
    }
}

void GameState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    pipe->drawPipes();
    land->drawLand();
    bird->draw();
    flash->draw();
    hud->draw();
    _data->window.display();
}

