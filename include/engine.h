#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>

namespace Engine
{
    sf::Vector2f WorldIntoPixel(sf::Vector2f world, sf::View view);
    sf::Vector2f PixelIntoWorld(sf::Vector2f pixel, sf::View view);
    sf::Vector2f IntToFloat(sf::Vector2i int_vec);
};