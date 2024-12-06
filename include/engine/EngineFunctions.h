#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>

namespace Engine
{
    sf::Vector2f IntToFloat(sf::Vector2i int_vec);
};