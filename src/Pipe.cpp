#include "Pipe.h"
#include <iostream>

Pipe::Pipe(GameDataRef data) : _data(data) {
    _landHeight = _data->assets.getTexture("Land").getSize().y;
    _pipeSpawnYOffset = 0;
}

void Pipe::spawnBottomPipe() {
    sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
    sprite.setPosition(
        _data->window.getSize().x,
        _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset
    );
    pipeSprites.push_back(sprite);
}

void Pipe::spawnTopPipe() {
    sf::Sprite sprite(_data->assets.getTexture("Pipe Down"));
    sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset);
    pipeSprites.push_back(sprite);
}

void Pipe::movePipes(float delta) {
    for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
        if(pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
            pipeSprites.erase(pipeSprites.begin() + i);
        } else {
            float movement = PIPE_MOVEMENT_SPEED * delta;
            pipeSprites.at(i).move(-movement, 0);
        }
    }
}

void Pipe::spawnInvisiblePipe() {
    sf::Sprite sprite(_data->assets.getTexture("Pipe Up"));
    sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);\
    sprite.setColor(sf::Color(0, 0, 0, 0));
    pipeSprites.push_back(sprite);
}

void Pipe::drawPipes() {
    for (unsigned short int i = 0; i < pipeSprites.size(); i++) {
        _data->window.draw(pipeSprites.at(i));
    }
}

void Pipe::randomizePipeOffset() {
    _pipeSpawnYOffset = rand() % (_landHeight + 1);
}
