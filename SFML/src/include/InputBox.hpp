#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

class InputBox {
public:
    //* arg: size, position, Font/
    InputBox(sf::Vector2f size, sf::Vector2f position, sf::Font& font);
    void draw(sf::RenderWindow& window);
    void checkFocus(sf::Vector2i mousePos);
    void handleInput(sf::Event event);

private:
    sf::RectangleShape box;
    sf::Text text;
    std::string inputString;
    bool isActive;
};

#endif // INPUTBOX_HPP
