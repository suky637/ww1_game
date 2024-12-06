#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "gamelogic.h"

#define MAX_FPS 1.f / 60.f

void doEvents(sf::RenderWindow* win, Game* game)
{
    sf::Event event;
    while (win->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            win->close();
            break;
        }
        case sf::Event::MouseWheelScrolled:
        {
            if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
            {
                float delta = event.mouseWheelScroll.delta;
                game->scroll = delta;
            }
            break;
            }
         default:
            break;
        }
    }
}

int main(int, char**){


    sf::RenderWindow window{sf::VideoMode(1280, 720), "Window"};
    window.setVerticalSyncEnabled(false);

    Game game{&window};

    game.Begin();
    float lastTime = 0;
    float accumulation = 0;
    sf::Clock clock;

    while (window.isOpen())
    {
        float crntTime = clock.getElapsedTime().asSeconds(); 
        
        doEvents(&window, &game);

        float dt = crntTime - lastTime;
        game.Update(dt);
        accumulation += dt;
        while (accumulation >= MAX_FPS)
        {
            accumulation -= MAX_FPS;
            game.FixedUpdate();
        }
        

        game.Render();

        window.display();

        game.scroll = 0;
        lastTime = crntTime;
    }

    


    return 0;
}
