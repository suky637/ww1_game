#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>

class Component
{
    public:
    //Component();
    bool isClicked = false;
    sf::RenderWindow* win;
    sf::Vector2f position;
    sf::Vector2f size;
    virtual void Input(sf::View* view);
    virtual void Draw(sf::Font font);
};