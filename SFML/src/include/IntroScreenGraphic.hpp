
#ifndef INTROSCREENGRAPHIC_HPP
#define INTROSCREENGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "Element.hpp"
#include "InputBox.hpp"
#include <memory>

class IntroScreenGraphic {
private:
    sf::RenderWindow* window;
    int screenWidth;
    int screenHeight;
    std::unique_ptr<Element> element;
    sf::Font fontOswald;

    // Declare input boxes
    InputBox inputBox1;
    InputBox inputBox2;

    // Textures
    std::shared_ptr<sf::Texture> backgroundTexture;
    std::shared_ptr<sf::Texture> profileTexture;

public:
    // Constructor
    IntroScreenGraphic(sf::RenderWindow* window, int screenWidth, int screenHeight);

    // Methods
    void loadIntroTexture();
    void unloadAllIntroTextures();
    void displayIntro();
    void handleMouseInput(sf::Vector2i mousePos);
    void handleTextInput(sf::Event event);
};

#endif
