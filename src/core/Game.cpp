/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Game.hpp"
#include "../levels/LevelOne.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>

Game::Game() {
}

Game::~Game() {
}

int Game::run(sf::RenderWindow& window) {

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

    return(-1);
}