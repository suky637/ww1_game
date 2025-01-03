#include "myguilib/Label.h"

Label::Label(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, int size, std::string text, std::string id)
{
    this->win = win;
    this->position = pos;
    this->label.setFont(gui.font);
    this->label.setString(text);
    this->label.setCharacterSize(size);
    this->label.setPosition(pos);
    this->label.setFillColor(sf::Color::White);
    this->label.setStyle(sf::Text::Style::Regular);

    gui.components.insert_or_assign(id == "" ? text : id, std::make_unique<Label>(*this));
}

void Label::Draw(sf::Font font)
{
    this->label.setFont(font);
    win->draw(this->label);
}