#ifndef FLAPPY_BIRD_GAMESTATE_H
#define FLAPPY_BIRD_GAMESTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

class GameState : public State {
private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _background;
    Pipe *pipe;
    Land *land;
    Bird *bird;
    Flash *flash;
    HUD *hud;
    Collision collision;
    sf::Clock clock;
    int _gameState;
    int _score;
public:
    GameState(GameDataRef data);
    void init();
    void handleInput();
    void update(float delta);
    void draw(float delta);
};


#endif //FLAPPY_BIRD_GAMESTATE_H
