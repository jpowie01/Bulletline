/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Game.hpp"
#include "../levels/LevelOne.hpp"
#include "Player.hpp"

#include <sstream>
#include <SFML/Graphics.hpp>

#include "../helpers/ResourcePath.hpp"

string int2string(int number) {
    // TODO: Create utils class for this
    string out;
    stringstream ss;
    ss << number;
    ss >> out;
    return out;
}

Game::Game() {
}

Game::~Game() {
}

int Game::run(sf::RenderWindow& window) {
    // Load font
    sf::Font arial;
    if (!arial.loadFromFile(resourcePath() + "/assets/fonts/Arial.ttf")) {
        printf("Error loading font (Arial.ttf)!\n");
        return -1;
    }
    
    // Heart sprite
    sf::Texture heartTexture;
    if (!heartTexture.loadFromFile(resourcePath() + "/assets/images/heart.png")) {
        printf("Error loading heart texture (heart.png)!\n");
        return -1;
    }
    sf::Sprite heartSprite(heartTexture);
    heartSprite.setPosition(30, 620);
    
    // Health text
    sf::Text healthText;
    healthText.setString("100");
    healthText.setFont(arial);
    healthText.setPosition(80, 618);
    healthText.setCharacterSize(36);

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
        
        // Update GUI
        healthText.setString(int2string(player->getHealth()));

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        levelOne->draw(window);
        
        // Draw GUI
        window.draw(heartSprite);
        window.draw(healthText);

        // Update the window
        window.display();
    }

    // Release memory
    delete levelOne;

    return(-1);
}