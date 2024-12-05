#include "camera_movement.h"
#include <math.h>

CameraMovement::CameraMovement()
{
    zoom = 1.f;
}

void CameraMovement::Start()
{

}

void CameraMovement::ResetZoom(float* acc)
{
    float inv = 1.f / *acc;
    view->zoom(inv);
    *acc = 1.f;
}

void CameraMovement::Update()
{
    static float acc = 1.f;
    if (scroll == 0)
    {

    }
    else if (scroll == 1)
    {
        acc *= 0.97f;
        view->zoom(0.97f);
    }
    else if (scroll == -1)
    {
        acc *= 1.03f;
        view->zoom(1.03f);
    }

    // Movement
    #define SPEED 100.f
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        view->move(sf::Vector2f(0, -SPEED * deltaTime * acc));
        y += -SPEED * deltaTime * acc;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        view->move(sf::Vector2f(0, SPEED * deltaTime * acc));
        y += SPEED * deltaTime * acc;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        view->move(sf::Vector2f(-SPEED * deltaTime * acc, 0));
        x += -SPEED * deltaTime * acc;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        view->move(sf::Vector2f(SPEED * deltaTime * acc, 0));
        x += SPEED * deltaTime * acc;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        ResetZoom(&acc);
    }
}

void CameraMovement::FixedUpdate()
{

}

void CameraMovement::Draw()
{

}