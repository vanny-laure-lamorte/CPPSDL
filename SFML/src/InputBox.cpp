
//* arg: size, position, Font/
//* implementation of the InputBox class/
//* Create input boxes:
//*     InputBox inputBox1(sf::Vector2f(300, 50), sf::Vector2f(100, 150), font);



//* Method to draw the input box
//* args: window
//* implementation of the InputBox class/
//* to put into render loop


//* Method to check if the input box is in focus
//* args: mousePos
//* implementation of the InputBox class/
//* to put into event loop
//* Handle mouse clicks for focus
//             *handle input
        //     if (event.type == sf::Event::MouseButtonPressed)
        //     {
        //         sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        //         inputBox1.checkFocus(mousePos);
        //         inputBox2.checkFocus(mousePos);
        //     }
        //      *handle input
        //     inputBox1.handleInput(event);
        //     inputBox2.handleInput(event);
        // }


//* Method to handle input
//* args: event
//* implementation of the InputBox class/
//* to put into event loop
//* Handle text input
//             *handle input
        //     if (event.type == sf::Event::TextEntered)
        //     {
        //         inputBox1.handleInput(event);
        //         inputBox2.handleInput(event);
        //     }
        // }


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
        if (event.text.unicode == '\b' && !inputString.empty()) // Backspace
        {
            inputString.pop_back();
        }
        else if (event.text.unicode < 128 && event.text.unicode != '\b') // Add character
        {
            inputString += static_cast<char>(event.text.unicode);
        }
        text.setString(inputString);
    }
}
