#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include "Obstacle.h"
#include "Player.hpp"

int main(int, char const**)
{
    // Window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 680), "CS 1.5 Alpha", sf::Style::Close, settings);

    // Create player
    Player* player = new Player(20.0f, 20.0f);

	//Create obstacle
	Obstacle* obstacle1 = new Obstacle(10, 10, 30, 50);

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

        // Move player
        // TODO: Repair walking in both X&Y axis
        float movement = player->getSpeed() * lastFrame.asSeconds();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player->move(-movement, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player->move(movement, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            player->move(0.0f, movement);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            player->move(0.0f, -movement);
        }

        // Clear screen
        window.clear(sf::Color::White);

        // Draw player
        player->draw(window);

		//Draw obstacle
		obstacle1->draw(window);

        // Update the window
        window.display();

        // Set last frame
        lastFrame = clock.getElapsedTime();
        clock.restart();
    }

    return EXIT_SUCCESS;
}
