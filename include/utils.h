#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include <memory>

#define FixedDeltaTime (1 / 60)

class Script;

class Scene
{
    public:
    float deltaTime;
    sf::RenderWindow* window;
    std::string sceneName;
    int scroll;
    
    virtual void Start();
    virtual void Update();
    virtual void FixedUpdate();
    virtual void Draw();
};

class Script
{
    public:
    float deltaTime;
    int scroll;

    virtual void Start();
    virtual void Update();
    virtual void FixedUpdate();
    virtual void Draw();
};