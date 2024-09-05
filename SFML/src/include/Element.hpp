#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Element
{
public:
    Element(sf::RenderWindow *window);
    ~Element();

    // Images
    std::shared_ptr<sf::Texture> CreateTexture(const std::string &imagePath);
    void renderTexture(const std::shared_ptr<sf::Texture> &texture, int x, int y, int width, int height);

    // Fonts
    std::shared_ptr<sf::Font> LoadFont(const std::string &fontPath);

    void displayText(const std::shared_ptr<sf::Font> &font, const std::string &writeText, sf::Color color, int x, int y, bool isCentered, int screenWidth, int screenHeight);

    // Rectangle
    void drawRoundedRect(float x, float y, float width, float height, float radius, sf::Color color);

    // Colors
    const sf::Color COLOR_BLACK = sf::Color::Black;
    const sf::Color COLOR_WHITE = sf::Color::White;

private:
    sf::RenderWindow *window;
    std::shared_ptr<sf::Texture> imageTexture;
    std::shared_ptr<sf::Font> font;
};

#endif // ELEMENT_HPP