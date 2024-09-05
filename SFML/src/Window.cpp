#include "include/Window.hpp"
#include <iostream>

Window::Window(int screenWidth, int screenHeight) 
    : screenWidth(screenWidth), screenHeight(screenHeight), initialized(false) {
    try {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(screenWidth, screenHeight), "TILE TWISTER by Lucas, Thanh & Vanny");
        initialized = true;
    } catch (const std::exception& e) {
        std::cerr << "Failed to create SFML window: " << e.what() << std::endl;
    }
}

Window::~Window() {
    // std::unique_ptr will automatically delete the window, no need for explicit deletion
}

bool Window::isInitialized() const {
    return initialized;
}

void Window::update() {
    if (!initialized) return;

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }

    window->clear(sf::Color(50, 50, 50));
    window->display();
}

sf::RenderWindow* Window::getWindow() const {
    return window.get();
}