// Create an SFML window and draw a circle in the center

#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/window_context_handler.cpp"

int main()
{

//    WindowContextHandler windowContextHandler(800, 600, "SFML window");
    // Create an instance of the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    window.setFramerateLimit(2000);

    // Create a circle shape
    int radius = 10;
    sf::CircleShape circle(radius);
    circle.setFillColor(sf::Color::Green);

    int x, y;
    x = 400;
    y = 300;

    int x_inc = 1;
    int y_inc = 1;
    circle.setPosition(x,y);

    // change anchor point to center
    circle.setOrigin(radius, radius);

    int num_shapes = 1;

    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the circle
        window.draw(circle);

        // Write the number of shapes in the window to upper left corner
        sf::Text text;
        // use the fonts under the res folder
        sf::Font font;
        font.loadFromFile("res/OpenSans-Regular.ttf");
        text.setFont(font);
        text.setString("Number of shapes: " + std::to_string(num_shapes));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(10, 10);
        window.draw(text);

        // Update the window
        window.display();

        x += x_inc;
        y += y_inc;

        if (x >= 800 - radius || x <= radius){
            x_inc *= -1;
            x += 2*x_inc;
        }

        if (y >= 600 - radius || y <= radius) {
            y_inc *= -1;
            y += 2*y_inc;
        }

        circle.setPosition(x,y);






    }

    return 0;
}