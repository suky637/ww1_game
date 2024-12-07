#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "engine.h"
#include "myguilib/Component.h"

class GUI: public Script
{
    public:
    sf::Font font;
    bool hovered;
    GUI();
    GUI(sf::Font& font);
    sf::View* gui_view;
    sf::RenderWindow* window;
    std::map<std::string, std::unique_ptr<Component>> components{};
    void Update(bool gui_hovered) override;
    void Draw() override;
    bool isClicked(std::string id);
    std::string getId() override;
    GUI* getScript() override;

};