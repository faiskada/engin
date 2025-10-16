//
// Created by faiskada on 14/10/2025.
//
#include <string>
#include "SDL.h"

#ifndef ENGIN_ENGINE_H
#define ENGIN_ENGINE_H


class Engine {
    bool isRunning;
protected:
    double targetFps;
    double targetFrameTime;
    
    //bool vSync;
    //int windowWidth;
    //int windowHeight; 
    //std::string windowTitle;
    //SDL_Window *window = nullptr;
    
    virtual void on_enter();
    virtual void input();
    virtual void update(const double &dt);
    virtual void render();
    virtual void on_exit();
    
public:
    virtual ~Engine() = default;

    void run();
    void exit();

    const bool* const IsRunning;
    
    Engine(const double targetFps, const int windowWidth, const int windowHeight, const std::string& windowTitle);
};


#endif //ENGIN_ENGINE_H