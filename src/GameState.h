#ifndef FLAPPY_BIRD_GAMESTATE_H
#define FLAPPY_BIRD_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameState : public State {
private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
public:
    GameState(GameDataRef data);
    void init();
    void handleInput();
    void update(float delta);
    void draw(float delta);
};


#endif //FLAPPY_BIRD_GAMESTATE_H
