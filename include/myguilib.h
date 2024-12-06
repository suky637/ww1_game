#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "utils.h"

class Component;

class GUI: public Script
{
    public:
    sf::Font font;
    GUI();
    GUI(sf::Font& font);
    sf::View* gui_view;
    sf::RenderWindow* window;
    std::map<std::string, std::unique_ptr<Component>> components{};
    void Update() override;
    void Draw() override;
    std::string getId() override;
    GUI* getScript() override;

};

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

class Button: public Component
{
    private:
    sf::Text label;
    sf::RectangleShape rect{};
    bool lastClick = false;
    bool crntClicked = false;
    public:
    Button(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, sf::Vector2f size, std::string text, std::string id = "");
    void Input(sf::View* view) override;
    void Draw(sf::Font font) override;
};

class Label: public Component
{
    private:
    sf::Text label;
    public:
    Label(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, int size, std::string text, std::string id = "");
    void Draw(sf::Font font) override;
};

class Frame: public Component
{
    private:
    sf::RectangleShape rect;
    public:
    Frame(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, sf::Vector2f size, std::string id = "");
    void Draw(sf::Font font) override;
};