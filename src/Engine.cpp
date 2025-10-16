//
// Created by faiskada on 14/10/2025.
//

#include "../include/Engine.h"
#include <chrono>
#include <thread>
#include "SDL.h"

using engineClock = std::chrono::high_resolution_clock;

void Engine::run() {
    this->isRunning = true;
    this->on_enter();
    
    auto lastFrame = engineClock::now();
    std::chrono::time_point<std::chrono::system_clock> currentFrame;
    
    double dt;
    std::chrono::duration<double> sleepTime{};

    while(this->isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                this->exit();
            }
        }
        
        this->input();
        
        currentFrame = engineClock::now();
        dt = static_cast<double>((currentFrame - lastFrame).count());
        
        lastFrame = currentFrame;
        sleepTime = std::chrono::duration<double>(this->targetFrameTime - dt);
        
        this->update(dt);
        this->render();
        
        if (/*!this->vSync &&*/ sleepTime.count() > 0.0) {
            std::this_thread::sleep_for(sleepTime);
        }
    }
}


void Engine::on_enter()
{}

void Engine::input()
{}

void Engine::update(const double &dt)
{}

void Engine::render() {

}

void Engine::on_exit() {}

void Engine::exit() {
    isRunning = false;
    this->on_exit();
}


Engine::Engine(const double targetFps, const int windowWidth, const int windowHeight, const std::string& windowTitle) :
isRunning(false),
targetFps(targetFps),
targetFrameTime(1.0/targetFps),
IsRunning(&isRunning)
{}
