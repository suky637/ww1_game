#include "scene_map.h"


Europe::Europe() : sceneName{"europe"}
{

    if (!font.loadFromFile("ressources/LiberationSerif-Regular.ttf"))
    {
        std::cerr << "Failed to load font\n";
        exit(1);
    }

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

    //gui_view = sf::View(*view);
    CameraMovement cameraMovement{};
    cameraMovement.view = view;
    cameraMovement.Start();
    scripts.push_back(std::make_unique<CameraMovement>(std::move(cameraMovement)));

    //font.loadFromFile("ressources/LiberationSerif-Regular.ttf");
    //font.

    //test = sf::Text("Test", font);

    GUI gui = GUI{font};
    gui.window = window;
    gui.gui_view = gui_view;
    // adding buttons now?
    Frame frame{window, gui, sf::Vector2f(0, 0), sf::Vector2f(260, 100), "0"};
    Button button{window, gui, sf::Vector2f(10, 10), sf::Vector2f(240, 40), "Hello, World!", "1"};
    Label label{window, gui, sf::Vector2f(10, 50), 24, "HELLO"};
    //Frame frame2{window, gui, sf::Vector2f(120, 100), sf::Vector2f(100, 100), "3"};

    scripts.push_back(std::make_unique<GUI>(std::move(gui)));
}

void Europe::Update()
{
    for (const auto& script : scripts)
    {
        script->scroll = scroll;
        script->deltaTime = deltaTime;
        script->Update();

        if (script->getId() == "GUI")
        {
            GUI* gui = (GUI*)script->getScript();
            if (gui->components.at("1")->isClicked)
            {
                std::cout << "Works using even higher level.\n";
            }
        }
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
    //window->draw(test);
    for (const auto& script : scripts)
    {
        script->Draw();
    }
}