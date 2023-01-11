#ifndef FLAPPY_BIRD_PIPE_H
#define FLAPPY_BIRD_PIPE_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "DEFINITIONS.h"

class Pipe {
private:
    GameDataRef _data;
    std::vector<sf::Sprite> pipeSprites;
    std::vector<sf::Sprite> scoringPipes;
    int _landHeight;
    int _pipeSpawnYOffset;
public:
    Pipe(GameDataRef data);
    void spawnBottomPipe();
    void spawnTopPipe();
    void spawnInvisiblePipe();
    void spawnScoringPipe();
    void movePipes(float delta);
    void drawPipes();
    void randomizePipeOffset();
    const std::vector<sf::Sprite> &getSprites() const;
    std::vector<sf::Sprite> &getScoringSprites();
};


#endif //FLAPPY_BIRD_PIPE_H
