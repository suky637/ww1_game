#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <vector>
#include <memory>

#define FixedDeltaTime (1 / 60)

class Script
{
    public:
    float deltaTime;
    int scroll;
    
    virtual void Start();
    virtual void Update(bool gui_hovered);
    virtual void FixedUpdate();
    virtual void Draw();
    virtual std::string getId();
    virtual Script* getScript();
};