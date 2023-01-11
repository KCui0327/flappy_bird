#include <iostream>
#include <sstream>
#include "DEFINITIONS.h"
#include "GameOverState.h"
#include "GameState.h"
#include <fstream>

GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score) {

}

void GameOverState::init() {
    std::ifstream readFile;
    readFile.open(HIGH_SCORE_FILEPATH);

    if (readFile.is_open()) {
        while (!readFile.eof()) {
            readFile >> _highScore;
        }
    }

    readFile.close();

    std::ofstream writeFile(HIGH_SCORE_FILEPATH);

    if (writeFile.is_open()) {
        if (_score > _highScore) _highScore = _score;
        writeFile << _highScore;
    }

    writeFile.close();

    _data->assets.loadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
    _data->assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
    _data->assets.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
    _data->assets.loadTexture("Bronze Medal", MEDAL_BRONZE_FILEPATH);
    _data->assets.loadTexture("Silver Medal", MEDAL_SILVER_FILEPATH);
    _data->assets.loadTexture("Gold Medal", MEDAL_GOLD_FILEPATH);
    _data->assets.loadTexture("Plat Medal", MEDAL_PLAT_FILEPATH);

    _background.setTexture(this->_data->assets.getTexture("Game Over Background"));
    _gameOverTitle.setTexture(this->_data->assets.getTexture("Game Over Title"));
    _gameOverContainer.setTexture(this->_data->assets.getTexture("Game Over Body"));
    _retryButton.setTexture(this->_data->assets.getTexture("Play Button"));

    _gameOverContainer.setPosition(
        (_data->window.getSize().x / 2) - (_gameOverContainer.getGlobalBounds().width / 2),
        (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height/ 2)
    );

    _gameOverTitle.setPosition(
        (_data->window.getSize().x / 2) - (_gameOverTitle.getGlobalBounds().width / 2),
        (_data->window.getSize().y / 2) - (_gameOverContainer.getGlobalBounds().height * 1.2)
    );

    _retryButton.setPosition(
        (_data->window.getSize().x / 2) - (_retryButton.getGlobalBounds().width / 2),
        _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height +
        (_retryButton.getGlobalBounds().height * 0.2)
    );

    _scoreText.setFont(_data->assets.getFont("Flappy Font"));
    _scoreText.setString(std::to_string(_score));
    _scoreText.setCharacterSize(56);
    _scoreText.setFillColor(sf::Color::White);
    _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
    _scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);

    _highScoreText.setFont(_data->assets.getFont("Flappy Font"));
    _highScoreText.setString(std::to_string(_highScore));
    _highScoreText.setCharacterSize(56);
    _highScoreText.setFillColor(sf::Color::White);
    _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2, _highScoreText.getGlobalBounds().height / 2);
    _highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);

    if (_score >= PLAT_MEDAL_SCORE) _medal.setTexture(_data->assets.getTexture("Plat Medal"));
    else if (_score >= GOLD_MEDAL_SCORE) _medal.setTexture(_data->assets.getTexture("Gold Medal"));
    else if (_score >= SILVER_MEDAL_SCORE) _medal.setTexture(_data->assets.getTexture("Silver Medal"));
    else if (_score >= BRONZE_MEDAL_SCORE) _medal.setTexture(_data->assets.getTexture("Bronze Medal"));

    _medal.setPosition(175, 465);
}

void GameOverState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
        if (_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
            _data->machine.addState(StateRef(new GameState(_data)), true);
        }
    }
}

void GameOverState::update(float delta) {
}

void GameOverState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_gameOverContainer);
    _data->window.draw(_gameOverTitle);
    _data->window.draw(_retryButton);
    _data->window.draw(_scoreText);
    _data->window.draw(_highScoreText);
    _data->window.draw(_medal);
    _data->window.display();
}

