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
    {
        viewport.setViewport(sf::FloatRect((1.f - ratio_width) / 2.f, 0.f, ratio_width, 1.f));
        gui_viewport.setViewport(sf::FloatRect((1.f - ratio_width) / 2.f, 0.f, ratio_width, 1.f));
    }
    else
    {
        viewport.setViewport(sf::FloatRect(0.f, (1.f - ratio_height) / 2.f, 1.f, ratio_height));
        gui_viewport.setViewport(sf::FloatRect((1.f - ratio_width) / 2.f, 0.f, ratio_width, 1.f));
    }
}

void Game::Begin()
{
    std::fstream f{"ressources/window.json"};
    json data = json::parse(f);

    std::string title = data["window_name"];
    win->setTitle(title);
    win->setSize(sf::Vector2u(data["default_width"], data["default_height"]));
    sf::Texture tex;
    tex.loadFromFile(data["icon"]);
    unsigned char* pixels = new unsigned char[tex.getSize().x * tex.getSize().y * 4];
    tex.update(pixels, 0, 0, tex.getSize().x, tex.getSize().y);
    win->setIcon(tex.getSize().x, tex.getSize().y, pixels);
    defaultWindow = win->getView();
    viewport = win->getView();
    gui_viewport = win->getView();

    Europe europe{};
    europe.window = win;
    europe.view = &viewport;
    europe.gui_view = &gui_viewport;
    europe.Start();
    scenes.push_back(std::make_unique<Europe>(std::move(europe)));
}

void Game::Update(float dt)
{
    for (const auto& scene : scenes)
    {
        scene->scroll = scroll;
        scene->deltaTime = dt;
        scene->Update();
    }
    sf::Vector2f mouseCoord = win->mapPixelToCoords(sf::Mouse::getPosition(*win), viewport);
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

    for (const auto& scene : scenes)
    {
        scene->Draw();
    }
}