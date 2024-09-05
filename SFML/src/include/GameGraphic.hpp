#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "Element.hpp"
#include <memory>

class GameGraphic {
public:
    GameGraphic(sf::RenderWindow* window, int screenWidth, int screenHeight);
    ~GameGraphic() = default; // Use default destructor since smart pointers will handle cleanup
    void loadTexture();
    void displayTexture();

    // Font
    void displayTitle();

private:
    std::unique_ptr<Element> element;
    sf::RenderWindow* window;
    int screenWidth;
    int screenHeight;

    std::shared_ptr<sf::Texture> backgroundTexture;
    std::shared_ptr<sf::Texture> testTexture;
    
    void animation();
    float animTransition = 0;

    // Font
    sf::Font fontOswald;

    void unloadAllTextures(); // Now a private method, rarely needed
};

#endif // GAMEGRAPHIC_HPP