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

    void displayText(const std::shared_ptr<sf::Font> &font, const std::string &writeText, int policeSize, sf::Color color, int x, int y, bool isCentered, int screenWidth, int screenHeight);

    // Rectangle
    void drawRoundedRect(float x, float y, float width, float height, float radius, sf::Color color);
    void drawRoundedRectOpacity(float x, float y, float width, float height, float radius, sf::Color color);
    void TransparentRect(float x, float y, float width, float height, float radius, sf::Color color, int opacityLevel);

    // Colors
    const sf::Color COLOR_WHITE = sf::Color(255, 255, 255);
    const sf::Color COLOR_BLACK = sf::Color(0, 0, 0);
    const sf::Color COLOR_PINK = sf::Color(212, 74, 121);
    const sf::Color COLOR_BLUE = sf::Color(49, 194, 224);
    const sf::Color COLOR_LIGHTGREY1 = sf::Color(222, 229, 234);
    const sf::Color COLOR_LIGHTGREY2 = sf::Color(118, 118, 118);
    const sf::Color COLOR_DARKGREY1 = sf::Color(13, 17, 23);
    const sf::Color COLOR_DARKGREY2 = sf::Color(63, 62, 62);

private:
    sf::RenderWindow *window;
    std::shared_ptr<sf::Texture> imageTexture;
    std::shared_ptr<sf::Font> font;
};

#endif // ELEMENT_HPP
