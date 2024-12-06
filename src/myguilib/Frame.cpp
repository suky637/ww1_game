#include "myguilib/Frame.h"

Frame::Frame(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, sf::Vector2f size, std::string id)
{
    this->win = win;
    this->position = pos;
    this->size = size;
    this->rect.setPosition(pos);
    this->rect.setSize(size);
    this->rect.setFillColor(sf::Color(61, 61, 61));
    gui.components.insert_or_assign(id == "" ? std::to_string(pos.x) + ";" + std::to_string(pos.y) : id, std::make_unique<Frame>(*this));
}

void Frame::Draw(sf::Font font)
{
    win->draw(this->rect);
}