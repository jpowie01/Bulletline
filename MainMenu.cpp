#include "MainMenu.hpp"

#include <SFML/Graphics.hpp>

MainMenu::MainMenu() {
    playing = false;
}

MainMenu::~MainMenu() {
}

int MainMenu::run(sf::RenderWindow& window) {

    sf::Text gameTitle;
    gameTitle.setColor(sf::Color::White);
    gameTitle.setString("Counter Strike 2D");
    gameTitle.setPosition({ 280.f, 160.f });

    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setPosition(50, 50);
    circle.setRadius(5);
    
    while (window.isOpen()) {

        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        window.draw(circle);

        // Update the window
        window.display();
    }
    return (-1);
}