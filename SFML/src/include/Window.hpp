#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Window {
public:
    Window(int screenWidth = 1050, int screenHeight = 700);
    ~Window();

    bool isInitialized() const;
    void update();
    sf::RenderWindow* getWindow() const;

private:
    std::unique_ptr<sf::RenderWindow> window;
    bool initialized;
    int screenWidth;
    int screenHeight;
};

#endif // WINDOW_HPP