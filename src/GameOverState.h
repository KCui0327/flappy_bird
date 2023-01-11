#ifndef FLAPPY_BIRD_GAMEOVERSTATE_H
#define FLAPPY_BIRD_GAMEOVERSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State {
private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _gameOverTitle;
    sf::Sprite _gameOverContainer;
    sf::Sprite _retryButton;
    sf::Sprite _medal;
    sf::Text _scoreText;
    sf::Text _highScoreText;
    int _score;
    int _highScore;
public:
    GameOverState(GameDataRef data, int score);
    void init();
    void handleInput();
    void update(float delta);
    void draw(float delta);
};


#endif //FLAPPY_BIRD_GAMEOVERSTATE_H
