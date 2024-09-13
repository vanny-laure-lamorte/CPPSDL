#ifndef INTROSCREENGRAPHIC_HPP
#define INTROSCREENGRAPHIC_HPP

#include "Element.hpp"
#include <iostream>
#include <cstring>

class IntroScreenGraphic
{
public:
    IntroScreenGraphic(sf::RenderWindow *window, int screenWidth, int screenHeight);

    ~IntroScreenGraphic() = default;

    std::unique_ptr<Element> element;
    sf::RenderWindow *window;    
    int screenWidth;
    int screenHeight;

    //*** FONT ***//
    sf::Font fontOswald;
    
    //*** LOAD & UNLOAD TEXTURES */
    void loadIntroTexture();
    void unloadAllIntroTextures();
    std::shared_ptr<sf::Texture> backgroundTexture; // Img Background
    std::shared_ptr<sf::Texture> profileTexture; // Img Profile 

    // *** DISPLAY ***//
    void displayIntro();

    //*** PSEUDO ***/

private:



    
    
};

#endif