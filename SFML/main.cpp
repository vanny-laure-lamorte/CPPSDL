#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <direct.h>

// int main()
// {
//     // Print the current working directory
//     char buffer[MAX_PATH];
//     _getcwd(buffer, MAX_PATH);
//     std::cout << "Current working directory: " << buffer << std::endl;
    
//     auto window = sf::RenderWindow{ { 900u, 600u }, "CMake SFML Project" };
//     window.setFramerateLimit(144);

//     //Load an animated sprite
//     float animTransition = 0;

//     sf::Texture textureAnimated;
//     if (!textureAnimated.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\img\\test.png"))
//         return EXIT_FAILURE;
//     sf::Sprite spriteAnimated(textureAnimated);

//     // Redimensionner l'image pour qu'elle s'adapte à la taille de la fenêtre
//     sf::Vector2u windowSizeAnimated = window.getSize();
//     sf::Vector2u textureSizeAnimated = textureAnimated.getSize();

//     // Centrer l'origine du sprite (son centre géométrique)
//     sf::FloatRect animatedRect = spriteAnimated.getLocalBounds();
//     spriteAnimated.setOrigin(animatedRect.width / 2.0f, animatedRect.height / 2.0f);

//     // Positionner le sprite au centre de la fenêtre
//     spriteAnimated.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

//     // float scaleXAnimated = static_cast<float>((windowSizeAnimated.x) / textureSizeAnimated.x) - animTransition;
//     // float scaleYAnimated = static_cast<float>((windowSizeAnimated.y) / textureSizeAnimated.y) - animTransition;

//     // spriteAnimated.setScale(scaleXAnimated, scaleYAnimated);



//     // Load a sprite to display
//     sf::Texture texture;
//     if (!texture.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\img\\background.jpg"))
//         return EXIT_FAILURE;
//     sf::Sprite sprite(texture);

//     // Redimensionner l'image pour qu'elle s'adapte à la taille de la fenêtre
//     sf::Vector2u windowSize = window.getSize();
//     sf::Vector2u textureSize = texture.getSize();

//     float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
//     float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

//     sprite.setScale(scaleX, scaleY);

//     // Load a font
//     sf::Font font;
//     if (!font.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\fonts\\Super Caramel.ttf"))
//     return EXIT_FAILURE;
//     sf::Text text;
//     text.setFont(font);
//     text.setString("TILE TWISTER");
//     text.setCharacterSize(50);
//     text.setFillColor(sf::Color::White);
//     text.setStyle(sf::Text::Bold);

//     sf::FloatRect textRect = text.getLocalBounds();
//     text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
//     text.setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 15.0f));

//     const float maxScale = 1.0f; // Échelle maximale pour le sprite animé


//     while (window.isOpen())
//     {
//         for (auto event = sf::Event{}; window.pollEvent(event);)
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }

//         if (animTransition < maxScale)
//         {
//             animTransition += 0.01f;
//         }
//         // Recalculate scale for animated sprite based on animTransition
//         // float scaleXAnimated = static_cast<float>((windowSize.x) / textureSizeAnimated.x );
//         // float scaleYAnimated = static_cast<float>((windowSize.y) / textureSizeAnimated.y );

//         // Appliquer l'échelle croissante au sprite animé
//         spriteAnimated.setScale(animTransition, animTransition);

//         // spriteAnimated.setScale(scaleXAnimated + animTransition, scaleYAnimated + animTransition);

//         window.clear();
//         window.draw(sprite);
//         window.draw(text);
//         window.draw(spriteAnimated);
//         window.display();
//     }

//     return EXIT_SUCCESS;
// }


#include <SFML/Graphics.hpp>
#include "src/include/Window.hpp"
#include "src/include/GameGraphic.hpp"

int SCREENWIDTH = 900;
int SCREENHEIGHT = 600;

int main() {

    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized()) {
        std::cerr << "Failed to initialize the window." << std::endl;
        return -1;
    }

    // Get the SFML window object
    sf::RenderWindow *renderWindow = window.getWindow();
    
    // Create game graphic instance
    GameGraphic gameGraphic(renderWindow, SCREENWIDTH, SCREENHEIGHT);
    
    // Main game loop
    while (renderWindow->isOpen()) {
        sf::Event event;
        while (renderWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                renderWindow->close();
            }
        }

        // Clear the screen
        renderWindow->clear(sf::Color(50, 50, 50)); // Dark gray

        // Display background and other textures
        gameGraphic.displayTexture();
        
        // Display what was drawn on the window
        renderWindow->display();
    }

    // No need to explicitly quit or delete resources, SFML handles that
    return EXIT_SUCCESS;
}
