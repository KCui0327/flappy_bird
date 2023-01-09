#ifndef FLAPPY_BIRD_INPUTMANAGER_H
#define FLAPPY_BIRD_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

class InputManager {
public:
    InputManager() { }
    ~InputManager() { }
    bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
    sf::Vector2i getMousePosition(sf::RenderWindow &window);
};


#endif //FLAPPY_BIRD_INPUTMANAGER_H
