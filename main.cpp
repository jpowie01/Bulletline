#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 680), "CS 1.5 alpha");

	//Create obstacle
	Obstacle* obstacle1 = new Obstacle(10,10,30,50);

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

        // Clear screen
        window.clear();

		//Draw obstacle
		obstacle1->draw(window);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
