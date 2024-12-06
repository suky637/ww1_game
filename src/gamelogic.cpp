#include "gamelogic.h"

Game::Game(sf::RenderWindow* window)
{
    this->win = window;
}

void Game::AdjustViewport()
{
    uint32_t width = win->getSize().x;
    uint32_t height = win->getSize().y;

    uint32_t desired_width = height / 9 * 16;
    uint32_t desired_height = width / 16 * 9;
    
    float ratio_width = (float)(desired_width) / (float)(width);
    float ratio_height = (float)(desired_height) / (float)(height);

    if (ratio_width < 1.f)
        viewport.setViewport(sf::FloatRect((1.f - ratio_width) / 2.f, 0.f, ratio_width, 1.f));
    else
        viewport.setViewport(sf::FloatRect(0.f, (1.f - ratio_height) / 2.f, 1.f, ratio_height));
}

void Game::Begin()
{
    win->setTitle("WW1 Game");
    defaultWindow = win->getView();
    viewport = win->getView();

    Europe europe{};
    europe.window = win;
    europe.view = &viewport;
    europe.Start();
    scenes.push_back(std::make_unique<Europe>(std::move(europe)));
}

void Game::Update(float dt)
{
    //std::cout << "UPDATE\n";
    for (const auto& scene : scenes)
    {
        scene->scroll = scroll;
        scene->deltaTime = dt;
        scene->Update();
    }
    sf::Vector2f mouseCoord = win->mapPixelToCoords(sf::Mouse::getPosition(*win), viewport);
    //std::cout << mousePix.x << ", " << mousePix.y << "\n";
}

void Game::FixedUpdate()
{
    AdjustViewport();
    for (const auto& scene : scenes)
    {
        scene->FixedUpdate();
    }
}


void Game::Render()
{
    win->setView(defaultWindow);
    win->clear(sf::Color::Black);

    win->setView(viewport);
    sf::RectangleShape bg{sf::Vector2f{1280, 720}};
    bg.setFillColor(sf::Color(20, 50, 100));
    win->draw(bg);

    for (const auto& scene : scenes)
    {
        scene->Draw();
    }
}