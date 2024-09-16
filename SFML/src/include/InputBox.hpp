#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

class InputBox {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string inputString;
    bool isActive;

public:
    // Constructor
    InputBox(sf::Vector2f size, sf::Vector2f position, sf::Font& font);

    // Methods
    void draw(sf::RenderWindow& window);
    void checkFocus(sf::Vector2i mousePos);
    void handleInput(sf::Event event);
    // Getter for input string
    std::string getInputString() { return inputString; }

};

#endif
