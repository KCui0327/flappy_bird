#ifndef FLAPPY_BIRD_HUD_H
#define FLAPPY_BIRD_HUD_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"

class HUD {
private:
    GameDataRef  _data;
    sf::Text _scoreText;
public:
    HUD(GameDataRef data);
    void draw();
    void updateScore(int score);
};


#endif //FLAPPY_BIRD_HUD_H
