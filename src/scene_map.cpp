#include "scene_map.h"


Europe::Europe() : sceneName{"europe"}
{
    // Loading ressources
    std::fstream f{"ressources/europe.json"};

    data = json::parse(f);

    // Loading every countries
    for (auto country : data.at("countries"))
    {
        std::cout << "Detected a country!, " << country.at("name") << "\n";
        for (auto region : country.at("regions"))
        {
            sf::ConvexShape shape{};
            shape.setFillColor(sf::Color(country.at("colour")["R"], country.at("colour")["G"], country.at("colour")["B"]));
            int index = 0;
            for (auto coord : region.at("coords"))
            {
                sf::Vector2f vec2;
                vec2.x = coord["X"];
                vec2.y = coord["Y"];
                shape.setPointCount(index+1);
                shape.setPoint(index, vec2);
                index++;
            }

            this->shapes.push_back(shape);
        }
    }
}

void Europe::Start()
{
    //std::cout << "SIZE: " << this->shapes.size() << "\n";

    gui_view = *view;
    CameraMovement cameraMovement{};
    cameraMovement.view = view;
    cameraMovement.Start();
    scripts.push_back(std::make_unique<CameraMovement>(std::move(cameraMovement)));



    GUI gui{};
    gui.window = window;
    gui.gui_view = view;

    // adding buttons now?
    Button button{window, sf::Vector2f(10, 10), sf::Vector2f(200, 20), "Hello, World!"};
    gui.components.push_back(std::make_unique<Button>(std::move(button)));

    scripts.push_back(std::make_unique<GUI>(std::move(gui)));
}

void Europe::Update()
{
    for (const auto& script : scripts)
    {
        script->scroll = scroll;
        script->deltaTime = deltaTime;
        script->Update();
    }
}

void Europe::FixedUpdate()
{
    for (const auto& script : scripts)
    {
        script->FixedUpdate();
    }
}

void Europe::Draw()
{
    
    for (auto shape : shapes)
    {
        this->window->draw(shape);
    }
    for (const auto& script : scripts)
    {
        script->Draw();
    }
}