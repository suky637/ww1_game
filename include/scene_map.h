#pragma once

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "utils.h"
#include "camera_movement.h"
#include "myguilib.h"

using json = nlohmann::json;

class Europe: public Scene
{
    private:
    std::vector<sf::ConvexShape> shapes{};
    std::vector<std::unique_ptr<Script>> scripts;
    sf::Font font;
    json data;
    public:
    sf::View* view;
    sf::View gui_view;
    std::string sceneName;
    Europe();
    void Start() override;
    void Update() override;
    void FixedUpdate() override;
    void Draw() override;
};
