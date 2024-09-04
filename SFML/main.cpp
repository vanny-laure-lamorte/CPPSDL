#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <direct.h>

int main()
{
    // Print the current working directory
    char buffer[MAX_PATH];
    _getcwd(buffer, MAX_PATH);
    std::cout << "Current working directory: " << buffer << std::endl;
    
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\img\\wallhaven-p8rmm9.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Load a font
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\fonts\\Super Caramel.ttf"))
    return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(text);
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
