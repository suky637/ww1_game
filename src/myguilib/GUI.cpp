#include "myguilib/GUI.h"

GUI::GUI()
{

}

GUI::GUI(sf::Font& font)
{
    this->font = sf::Font(font);
}

std::string GUI::getId()
{
    return "GUI";
}

GUI* GUI::getScript()
{
    return this;
}

void GUI::Update()
{
    for (const auto& [k, comp] : components)
    {
        comp->Input(gui_view);
    }
}

void GUI::Draw()
{
    window->setView(*gui_view);
    for (const auto& [k, comp] : components)
    {
        comp->Draw(font);
    }
    //std::cout << "Reached end!\n";
}