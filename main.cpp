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

    //Create first map - level one
    LevelOne* levelOne = new LevelOne();

    // Create player
    Player* player = new Player(400.0f, 200.0f);

    // Last frame for animation
    sf::Clock clock;
    sf::Time lastFrame;

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

        // Calculate player movement
        float movement = player->getSpeed() * lastFrame.asSeconds();
        float movementX = 0.0f;
        float movementY = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movementX -= movement;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movementX += movement;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movementY += movement;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movementY -= movement;
        }

        // Resolve walking in both directions
        if (movementX && movementY) {
            if (movementX >= 0) {
                movementX = sqrt(movementX);
            } else {
                movementX = -sqrt(-movementX);
            }
            if (movementY >= 0) {
                movementY = sqrt(movementY);
            } else {
                movementY = -sqrt(-movementY);
            }
        }

        // Check collisions in both directions
        player->move(movementX, 0.0f);
        if (levelOne->checkCollision(*player)) {
            player->move(-movementX, 0.0f);
        }
        player->move(0.0f, movementY);
        if (levelOne->checkCollision(*player)) {
            player->move(0.0f, -movementY);
        }

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        levelOne->draw(window);

        // Draw player
        player->draw(window);

        // Update the window
        window.display();

        // Set last frame
        lastFrame = clock.getElapsedTime();
        clock.restart();
    }

    return EXIT_SUCCESS;
}
