#ifndef FLAPPY_BIRD_STATE_H
#define FLAPPY_BIRD_STATE_H

class State {
public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw(float delta) = 0;
    virtual void pause() { }
    virtual void resume() { }
};

#endif //FLAPPY_BIRD_STATE_H
