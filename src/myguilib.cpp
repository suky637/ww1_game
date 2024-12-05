#include "myguilib.h"



/////////////////////////////////////////////////////////////////////////////////
// GUI SCRIPT
/////////////////////////////////////////////////////////////////////////////////

void GUI::Update()
{
    for (const auto& comp : components)
    {
        comp->Input();
    }
}

void GUI::Draw()
{
    for (const auto& comp : components)
    {
        comp->Draw();
    }
    //std::cout << "Reached end!\n";
}



/////////////////////////////////////////////////////////////////////////////////
// COMPONENTS
/////////////////////////////////////////////////////////////////////////////////

void Component::Input()
{

}

void Component::Draw()
{

}

/////////////////////////////////////////////////////////////////////////////////
// BUTTONS
/////////////////////////////////////////////////////////////////////////////////

Button::Button(sf::RenderWindow* win, sf::Vector2f pos, sf::Vector2f size, std::string text)
{
    if (!font.loadFromFile("ressources/LiberationSerif-Regular.ttf"))
    {
        std::cout << "FAILED TO LOAD FONT\n";
        exit(1);
    }

    this->win = win;
    this->position = pos;
    this->size = size;

    this->rect.setSize(size);
    this->rect.setPosition(pos);
    this->rect.setFillColor(sf::Color(91, 91, 91));

    this->label.setFont(font);
    this->label.setString(text);
    this->label.setCharacterSize(24);
    this->label.setColor(sf::Color(255, 255, 255));
    this->label.setStyle(sf::Text::Regular);

    const sf::FloatRect textRect = this->label.getLocalBounds();
    float xOff = this->rect.getSize().x / 2 - textRect.width / 2;
    float yOff = this->rect.getSize().y / 2 - textRect.height / 2;

    this->label.setOrigin(xOff, yOff);
    this->label.setPosition(this->rect.getPosition().x + this->rect.getSize().x / 2, this->rect.getPosition().y + this->rect.getSize().y / 2);
    
    std::cout << "Created Button Sucessfuly!\n";
}

void Button::Input()
{

}

void Button::Draw()
{
    //std::cout << "DRAW\n";
    if (win == nullptr)
        return;
    win->draw(rect);
    win->draw(label);
}