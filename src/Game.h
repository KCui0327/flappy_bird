#ifndef FLAPPY_BIRD_GAME_H
#define FLAPPY_BIRD_GAME_H

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

struct gameData {
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
} typedef GameData;

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
private:
    const float delta = 1.0f / 60.0f;
    sf::Clock _clock;
    GameDataRef _data = std::make_shared<GameData>();
    void run();
public:
    Game(int width, int height, std::string title);
};


#endif //FLAPPY_BIRD_GAME_H
