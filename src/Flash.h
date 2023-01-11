#ifndef FLAPPY_BIRD_FLASH_H
#define FLAPPY_BIRD_FLASH_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "DEFINITIONS.h"

class Flash {
private:
    GameDataRef _data;
    sf::RectangleShape _shape;
    bool _flashOn;
public:
    Flash(GameDataRef data);
    void show(float delta);
    void draw();
};


#endif //FLAPPY_BIRD_FLASH_H
