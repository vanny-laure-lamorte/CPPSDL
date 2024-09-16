#include "include/InputBox.hpp"

// Constructor
InputBox::InputBox(sf::Vector2f size, sf::Vector2f position, sf::Font& font)
    : font(font), isActive(false)
{
    box.setSize(size);
    box.setPosition(position);
    box.setFillColor(sf::Color::White);

    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(position.x + 10, position.y + 10);
}

// Draw the input box
void InputBox::draw(sf::RenderWindow& window)
{
    window.draw(box);
    window.draw(text);
}

// Check if the input box is in focus
void InputBox::checkFocus(sf::Vector2i mousePos)
{
    if (box.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        isActive = true;
        box.setOutlineThickness(2);
        box.setOutlineColor(sf::Color::Blue);
    }
    else
    {
        isActive = false;
        box.setOutlineThickness(0);
    }
}

// Handle text input
void InputBox::handleInput(sf::Event event)
{
    if (!isActive) return;

    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode == '\b' && !inputString.empty())
        {
            inputString.pop_back();
        }
        else if (event.text.unicode < 128 && event.text.unicode != '\b')
        {
            inputString += static_cast<char>(event.text.unicode);
        }
        text.setString(inputString);
    }
}
