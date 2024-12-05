#include "engine.h"

sf::Vector2f Engine::IntToFloat(sf::Vector2i int_vec)
{
    return sf::Vector2f(int_vec.x, int_vec.y);
}