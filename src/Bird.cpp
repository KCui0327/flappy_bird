#include "Bird.h"

Bird::Bird(GameDataRef data) : _data(data){
    _animationIterator = 0;
    _animationFrames.push_back(_data->assets.getTexture("Bird1"));
    _animationFrames.push_back(_data->assets.getTexture("Bird2"));
    _animationFrames.push_back(_data->assets.getTexture("Bird3"));
    _animationFrames.push_back(_data->assets.getTexture("Bird4"));
    _birdSprite.setTexture(_animationFrames.at(_animationIterator));
    _birdSprite.setPosition(
        (_data->window.getSize().x / 4 )  - _birdSprite.getGlobalBounds().width / 2,
        (_data->window.getSize().y / 2 )  - _birdSprite.getGlobalBounds().height / 2
    );

    _birdState = BIRD_STATE_STILL;
    sf::Vector2f origin = sf::Vector2f (
        _birdSprite.getGlobalBounds().width / 2,
        _birdSprite.getGlobalBounds().height / 2
    );

    _birdSprite.setOrigin(origin);

    _rotation = 0;
}

void Bird::draw() {
    _data->window.draw(_birdSprite);
}

void Bird::animate(float delta) {
    if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) {
        if (_animationIterator < _animationFrames.size() - 1) _animationIterator++;
        else _animationIterator = 0;
        _birdSprite.setTexture(_animationFrames.at(_animationIterator));
        _clock.restart();
    }
}

void Bird::update(float delta) {

    switch(_birdState) {
        case BIRD_STATE_FALLING:
            _birdSprite.move(0, GRAVITY * delta);
            _rotation += ROTATION_SPEED * delta;
            if (_rotation > 25.0f) _rotation = 25.0f;
            _birdSprite.setRotation(_rotation);
            break;
        case BIRD_STATE_FLYING:
            _birdSprite.move(0, -FLYING_SPEED * delta);
            _rotation -= ROTATION_SPEED * delta;
            if (_rotation < -25.0f) _rotation = -25.0f;
            _birdSprite.setRotation(_rotation);
            break;
        default:
            break;
    }

    if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) {
        _movementClock.restart();
        _birdState = BIRD_STATE_FALLING;
    }
}

void Bird::tap() {
    _movementClock.restart();
    _birdState = BIRD_STATE_FLYING;
}