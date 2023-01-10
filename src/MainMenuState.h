#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class MainMenuState : public State {
private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _title;
    sf::Sprite _playButton;
public:
    MainMenuState(GameDataRef data);
    void init();
    void handleInput();
    void update(float delta);
    void draw(float delta);
};