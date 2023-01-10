#include "MainMenuState.h"
#include "SplashState.h"
#include "GameState.h"
#include <sstream>
#include "DEFINITIONS.h"
#include <iostream>

MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

}

void MainMenuState::init() {
    _data->assets.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
    _data->assets.loadTexture("Game Title", GAME_TITLE_FILEPATH);
    _data->assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
    _background.setTexture(this->_data->assets.getTexture("Main Menu Background"));
    _title.setTexture(this->_data->assets.getTexture("Game Title"));
    _playButton.setTexture(this->_data->assets.getTexture("Play Button"));
    _title.setPosition(
        (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
        _title.getGlobalBounds().height / 2
    );
    _playButton.setPosition(
            (SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
            (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2)
    );
}

void MainMenuState::handleInput() {
    sf::Event event;

    while (_data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) _data->window.close();
        if (_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
            _data->machine.addState(StateRef(new GameState(_data)), true);
    }
}

void MainMenuState::update(float delta) {}

void MainMenuState::draw(float delta) {
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_title);
    _data->window.draw(_playButton);
    _data->window.display();
}
