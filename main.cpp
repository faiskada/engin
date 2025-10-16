#include <SDL2/SDL.h>
#include <iostream>
#include "include/Engine.h"
#include <format>

/*
 * TODO:
 * add friend functions for scalar [op] Vector2
 * make Vector2 tests
 * create renderer & rendering methods
 */

class MyGame : public Engine {
public:
    int frames = 0;

    MyGame(const double targetFps, const int windowWidth, const int windowHeight, const std::string& windowTitle) : Engine(targetFps, windowWidth, windowHeight, windowTitle)
    {}
protected:
    void update(const double &dt) override {
        frames++;
    }
};

int main() {
    const auto game = new MyGame(60.0, 800, 600, "My game");

    game->run();
    
    delete game;
    return 0;
}