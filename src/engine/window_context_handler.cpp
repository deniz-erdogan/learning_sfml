#pragma once
#include <SFML/Graphics.hpp>


class WindowContextHandler;

class WindowContextHandler {
public:
    WindowContextHandler(int width, int height, const char* title) {
        window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        window->setFramerateLimit(30);
    }

private:
    sf::RenderWindow* window;
};