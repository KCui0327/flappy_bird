#ifndef FLAPPY_BIRD_COLLISION_H
#define FLAPPY_BIRD_COLLISION_H

#include <SFML/Graphics.hpp>

class Collision {
public:
    Collision();
    bool checkSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);

};


#endif //FLAPPY_BIRD_COLLISION_H
