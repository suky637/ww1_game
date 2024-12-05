#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"

class Component;

class GUI: public Script
{
    public:
    sf::View* gui_view;
    sf::RenderWindow* window;
    std::vector<std::unique_ptr<Component>> components{};
    void Update() override;
    void Draw() override;

};

class Component
{
    public:
    //Component();
    sf::RenderWindow* win;
    sf::Vector2f position;
    sf::Vector2f size;
    virtual void Input();
    virtual void Draw();
};

class Button: public Component
{
    public:
    sf::Font font;
    sf::Text label;
    sf::RectangleShape rect;
    Button(sf::RenderWindow* win, sf::Vector2f pos, sf::Vector2f size, std::string text);
    void Input() override;
    void Draw() override;
};

class Label: public Component
{
    public:
    //void Input() override;
    void Draw() override;
};

class Frame: public Component
{
    public:
    void Input() override;
    void Draw() override;
};