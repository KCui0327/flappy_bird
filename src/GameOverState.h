//
// Created by Kencu on 2023-01-10.
//

#ifndef FLAPPY_BIRD_GAMEOVERSTATE_H
#define FLAPPY_BIRD_GAMEOVERSTATE_H
#ifndef FLAPPY_BIRD_GAMESTATE_H
#define FLAPPY_BIRD_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State {
private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
public:
    GameOverState(GameDataRef data);
    void init();
    void handleInput();
    void update(float delta);
    void draw(float delta);
};


#endif //FLAPPY_BIRD_GAMESTATE_H


#endif //FLAPPY_BIRD_GAMEOVERSTATE_H
