#ifndef FLAPPY_BIRD_LAND_H
#define FLAPPY_BIRD_LAND_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

class Land {
private:
    GameDataRef _data;
    std::vector<sf::Sprite> _landSprites;
public:
    Land(GameDataRef data);
    void moveLand(float delta);
    void drawLand();
};


#endif //FLAPPY_BIRD_LAND_H
