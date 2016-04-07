#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include "Obstacle.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "LevelOne.hpp"

int main(int, char const**)
{
    // Window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 680), "CS 1.5 Alpha", sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);

    // Create first map - level one
    LevelOne* levelOne = new LevelOne();

    // Create player
    Player* player = new Player(true, 400.0f, 200.0f, levelOne);

    // Add player into map
    levelOne->addPlayer(player);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Player shooting
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player->shot(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        }

        // Update the whole map
        levelOne->update();

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        levelOne->draw(window);

        // Update the window
        window.display();
    }

    // Release memory
    delete levelOne;

    // Exit game
    return EXIT_SUCCESS;
}
