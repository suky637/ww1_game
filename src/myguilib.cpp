#include "myguilib.h"



/////////////////////////////////////////////////////////////////////////////////
// GUI SCRIPT
/////////////////////////////////////////////////////////////////////////////////

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



/////////////////////////////////////////////////////////////////////////////////
// COMPONENTS
/////////////////////////////////////////////////////////////////////////////////

void Component::Input(sf::View* view)
{
}

void Component::Draw(sf::Font font)
{

}

/////////////////////////////////////////////////////////////////////////////////
// BUTTONS
/////////////////////////////////////////////////////////////////////////////////

Button::Button(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, sf::Vector2f size, std::string text, std::string id)
{
    this->win = win;
    this->position = pos;
    this->size = size;

    this->rect.setSize(size);
    this->rect.setPosition(pos);
    this->rect.setFillColor(sf::Color(91, 91, 91));

    this->label.setFont(gui.font);
    this->label.setString(text);
    this->label.setCharacterSize(64);
    float mul = size.y / 66;
    this->label.setScale(sf::Vector2f(mul, mul));
    this->label.setFillColor(sf::Color::White);
    this->label.setStyle(sf::Text::Regular);

    const sf::FloatRect textRect = this->label.getLocalBounds();

    //this->label.setOrigin(xOff, yOff);
    this->label.setPosition(
        position.x + (size.x / 2) - (textRect.width * mul / 2), 
        position.y + (size.y / 2) - (textRect.height * mul / 2 + 4 * (size.y / 20))
    );
    
    std::string _id = id == "" ? text : id;

    gui.components.insert_or_assign(_id, std::make_unique<Button>(*this));

    std::cout << "Created Button Sucessfuly!\n";
}

void Button::Input(sf::View* view)
{
    isClicked = false;
    // Checking if hovering
    sf::Vector2i pos = sf::Mouse::getPosition(*win);
    sf::Vector2f a = win->mapPixelToCoords(pos, *view);

    if (
        a.x < this->rect.getPosition().x + this->rect.getSize().x &&
        a.x > this->rect.getPosition().x &&
        a.y < this->rect.getPosition().y + this->rect.getSize().y &&
        a.y > this->rect.getPosition().y
    )
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            //std::cout << "CLICK BUTTON\n";
            lastClick = crntClicked;
            crntClicked = true;
        }
        else
        {
            crntClicked = false;
        }
        if (!crntClicked && lastClick)
        {
            isClicked = true;
            lastClick = false;
        }

        rect.setFillColor(sf::Color(81, 81, 81));
        return;
    }
    rect.setFillColor(sf::Color(91, 91, 91));
}

void Button::Draw(sf::Font font)
{
    //std::cout << "DRAW\n";
    if (win == nullptr)
        return;
    
    win->draw(rect);
    label.setFont(font);
    win->draw(label);
}

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

    std::string _id = id == "" ? text : id;

    gui.components.insert_or_assign(_id, std::make_unique<Label>(*this));
}

void Label::Draw(sf::Font font)
{
    this->label.setFont(font);
    win->draw(this->label);
}

Frame::Frame(sf::RenderWindow* win, GUI& gui, sf::Vector2f pos, sf::Vector2f size, std::string id)
{
    this->win = win;
    this->position = pos;
    this->size = size;
    std::string _id = id == "" ? std::to_string(pos.x) + ";" + std::to_string(pos.y) : id;
    this->rect.setPosition(pos);
    this->rect.setSize(size);
    this->rect.setFillColor(sf::Color(61, 61, 61));
    gui.components.insert_or_assign(_id, std::make_unique<Frame>(*this));
}

void Frame::Draw(sf::Font font)
{
    win->draw(this->rect);
}