#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "gamelogic.h"
#include "scroll_wheel.h"

#define MAX_FPS 1.f / 60.f

int main(int, char**){


    sf::RenderWindow window{sf::VideoMode(1280, 720), "Window"};
    window.setVerticalSyncEnabled(false);

    Game game{&window};

    game.Begin();
    float lastTime = 0;
    float accum = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float crntTime = clock.getElapsedTime().asSeconds(); 
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::MouseWheelScrolled:
            {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
                {
                    float delta = event.mouseWheelScroll.delta;
                    if (delta > 0)
                        game.scroll = 1;
                    else if (delta < 0)
                        game.scroll = -1;
                }
                break;
            }
            default:
                break;
            }
        }
        float dt = crntTime - lastTime;
        game.Update(dt);
        accum += dt;
        while (accum >= MAX_FPS)
        {
            accum -= MAX_FPS;
            game.FixedUpdate();
        }
        

        game.Render();

        window.display();

        game.scroll = 0;
        lastTime = crntTime;
    }

    


    return 0;
}
