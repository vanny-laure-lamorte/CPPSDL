#include "include/Element.hpp"
#include <iostream>

Element::Element(sf::RenderWindow *window) : window(window) 
{
    imageTexture = CreateTexture("assets\\img\\test.png");
    if (!imageTexture)
    {
        std::cout << "Error loading image" << std::endl;
    }

    // font = LoadFont("assets\\fonts\\Oswald.ttf");
    // if (!font)
    // {
    //     std::cout << "Error loading font" << std::endl;
    // }


}

Element::~Element() {
    // No need for explicit deletion since shared_ptr handles it.
}

//* IMAGES *//

std::shared_ptr<sf::Texture> Element::CreateTexture(const std::string &imagePath)
{
    auto texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(imagePath))
    {
        std::cerr << "Failed to load image: " << imagePath << std::endl;
        return nullptr;
    }
    return texture;
}

void Element::renderTexture(const std::shared_ptr<sf::Texture> &texture, int x, int y, int width, int height)
{
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    sprite.setPosition(x, y);
    sprite.setScale(static_cast<float>(width) / texture->getSize().x, static_cast<float>(height) / texture->getSize().y);
    window->draw(sprite);
}

//* FONTS *//

std::shared_ptr<sf::Font> Element::LoadFont(const std::string &fontPath)
{
    auto font = std::make_shared<sf::Font>();
    if (!font->loadFromFile(fontPath))
    {
        std::cerr << "Failed to load font: " << fontPath << std::endl;
        return nullptr;
    }
    return font;
}

void Element::displayText(const std::shared_ptr<sf::Font> &font, const std::string &writeText, int policeSize, sf::Color color, int x, int y, bool isCentered, int screenWidth, int screenHeight)
{
    sf::Text text;
    text.setFont(*font);
    text.setString(writeText);
    text.setCharacterSize(policeSize);
    text.setFillColor(color);

    if (isCentered)
    {
        text.setPosition(static_cast<float>(screenWidth) / 2 - text.getLocalBounds().width / 2,
                         static_cast<float>(screenHeight) / 2 - text.getLocalBounds().height / 2);
    }
    else
    {
        text.setPosition(x, y);
    }

    window->draw(text);
}


// Method to draw plain rect
//* args: x, y, width, height, radius, color /
void Element::drawRoundedRect(float x, float y, float width, float height, float radius, sf::Color color) 
{
    // Créer les quatre coins arrondis
    sf::CircleShape corner(radius);
    corner.setFillColor(color);
    corner.setPointCount(30); // Plus il y a de points, plus le cercle est lisse

    // Positionner les coins
    corner.setPosition(x, y); // Coin supérieur gauche
    window->draw(corner);

    corner.setPosition(x + width - radius * 2, y); // Coin supérieur droit
    window->draw(corner);

    corner.setPosition(x, y + height - radius * 2); // Coin inférieur gauche
    window->draw(corner);

    corner.setPosition(x + width - radius * 2, y + height - radius * 2); // Coin inférieur droit
    window->draw(corner);

    // Créer les quatre rectangles pour les côtés
    sf::RectangleShape horizontal(sf::Vector2f(width - radius * 2, radius)); // Côtés horizontaux
    horizontal.setFillColor(color);

    horizontal.setPosition(x + radius, y); // Haut
    window->draw(horizontal);

    horizontal.setPosition(x + radius, y + height - radius); // Bas
    window->draw(horizontal);

    sf::RectangleShape vertical(sf::Vector2f(radius, height - radius * 2)); // Côtés verticaux
    vertical.setFillColor(color);

    vertical.setPosition(x, y + radius); // Gauche
    window->draw(vertical);

    vertical.setPosition(x + width - radius, y + radius); // Droite
    window->draw(vertical);

    // Créer le rectangle central
    sf::RectangleShape center(sf::Vector2f(width - radius * 2, height - radius * 2));
    center.setFillColor(color);
    center.setPosition(x + radius, y + radius);
    window->draw(center);
}

// Method to draw transparent rect
//* args: x, y, width, height, radius, color /
void Element::drawRoundedRectOpacity(float x, float y, float width, float height, float radius, sf::Color color) 
{
    // Set transparency by adjusting the alpha channel of the color
    color.a = 128; // Adjust this value (0-255) to change transparency level, 128 is 50% transparency

    // Create the four rounded corners
    sf::CircleShape corner(radius);
    corner.setFillColor(color);
    corner.setPointCount(30); // More points make the circle smoother

    // Position the corners
    corner.setPosition(x, y); // Top-left corner
    window->draw(corner);

    corner.setPosition(x + width - radius * 2, y); // Top-right corner
    window->draw(corner);

    corner.setPosition(x, y + height - radius * 2); // Bottom-left corner
    window->draw(corner);

    corner.setPosition(x + width - radius * 2, y + height - radius * 2); // Bottom-right corner
    window->draw(corner);

    // Create the four rectangles for the sides
    sf::RectangleShape horizontal(sf::Vector2f(width - radius * 2, radius)); 
    horizontal.setFillColor(color);

    horizontal.setPosition(x + radius, y);
    window->draw(horizontal);

    horizontal.setPosition(x + radius, y + height - radius);
    window->draw(horizontal);

    sf::RectangleShape vertical(sf::Vector2f(radius, height - radius * 2)); 
    vertical.setFillColor(color);

    vertical.setPosition(x, y + radius); 
    window->draw(vertical);

    vertical.setPosition(x + width - radius, y + radius); 
    window->draw(vertical);

    // Create the center rectangle
    sf::RectangleShape center(sf::Vector2f(width - radius * 2, height - radius * 2));
    center.setFillColor(color);
    center.setPosition(x + radius, y + radius);
    window->draw(center);
}

void Element::TransparentRect(float x, float y, float width, float height, float radius, sf::Color color, int opacityLevel) 
{

    color.a = opacityLevel;

    // Create the rounded rectangle shape
    sf::CircleShape corner(radius);
    corner.setFillColor(color);
    corner.setPointCount(30); // More points make the circle smoother

    // Top-left corner
    corner.setPosition(x, y);
    window->draw(corner);

    // Top-right corner
    corner.setPosition(x + width - radius * 2, y);
    window->draw(corner);

    // Bottom-left corner
    corner.setPosition(x, y + height - radius * 2);
    window->draw(corner);

    // Bottom-right corner
    corner.setPosition(x + width - radius * 2, y + height - radius * 2);
    window->draw(corner);

    // Top side
    sf::RectangleShape top(sf::Vector2f(width - radius * 2, radius));
    top.setFillColor(color);
    top.setPosition(x + radius, y);
    window->draw(top);

    // Bottom side
    sf::RectangleShape bottom(sf::Vector2f(width - radius * 2, radius));
    bottom.setFillColor(color);
    bottom.setPosition(x + radius, y + height - radius);
    window->draw(bottom);

    // Left side
    sf::RectangleShape left(sf::Vector2f(radius, height - radius * 2));
    left.setFillColor(color);
    left.setPosition(x, y + radius);
    window->draw(left);

    // Right side
    sf::RectangleShape right(sf::Vector2f(radius, height - radius * 2));
    right.setFillColor(color);
    right.setPosition(x + width - radius, y + radius);
    window->draw(right);

    // Center
    sf::RectangleShape center(sf::Vector2f(width - radius * 2, height - radius * 2));
    center.setFillColor(color);
    center.setPosition(x + radius, y + radius);
    window->draw(center);
}