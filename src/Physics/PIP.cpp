#include "Physics/PIP.h"

bool Physics::PIP_Collision(sf::ConvexShape shape, sf::Vector2f point)
{
    // getting the functions
    int amount = 0;
    for (int i = 0; i < shape.getPointCount(); i++)
    {
        sf::Vector2f pointA = shape.getPoint(i);
        sf::Vector2f pointB = shape.getPoint((i + 1) % shape.getPointCount());
        if (pointA.x == pointB.x)
        {
            // impossible for a function
            if ((point.y > pointA.y && point.y <= pointB.y) || (point.y > pointB.y && point.y <= pointA.y))
                amount++;
            continue;
        }
        if (pointA.y == pointB.y)
        {
            // can decide to not overlap
            if (point.y == pointA.y && point.x >= std::min(pointA.x, pointB.x) && point.x <= std::max(pointA.x, pointB.x))
                return true;
            continue;
        }

        float m = (pointB.y - pointA.y) / (pointB.x - pointA.x);
        float b = pointA.y - m * pointA.x;
        float intersectionPointX = (point.y - b) / m;
        float domain_min = std::min(pointA.x, pointB.x);
        float domain_max = std::max(pointA.x, pointB.x);

        if (intersectionPointX >= domain_min && intersectionPointX <= domain_max && point.x <= intersectionPointX)
        {
            amount++;
        }
    }
    if (amount % 2 == 1) return true;
    return false;
}