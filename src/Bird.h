#ifndef FLAPPY_BIRD_BIRD_H
#define FLAPPY_BIRD_BIRD_H

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Game.h"
#include <vector>

class Bird {
private:
    GameDataRef _data;
    sf::Sprite _birdSprite;
    std::vector<sf::Texture> _animationFrames;
    unsigned int _animationIterator;
    sf::Clock _clock;
    sf::Clock _movementClock;
    int _birdState;
    float _rotation;
public:
    Bird(GameDataRef data);
    void draw();
    void animate(float delta);
    void update(float  delta);
    void tap();
    const sf::Sprite &getSprite() const;
};


#endif //FLAPPY_BIRD_BIRD_H
