/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "MainMenu.hpp"
#include "../helpers/ResourcePath.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

MainMenu::MainMenu() {
}

MainMenu::~MainMenu() {
}

int MainMenu::run(sf::RenderWindow& window) {

    // Set mouse position
    sf::Mouse::setPosition(sf::Vector2i(600, 600), window);
   
    // Load font
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Failed to load font file (Arial.ttf)");
        return (-1);
    }

    // Create Game Title
    sf::Text gameTitle;
    gameTitle.setColor(sf::Color::White);
    gameTitle.setCharacterSize(100);
    gameTitle.setString("Counter Strike 2D");
    gameTitle.setPosition(100,50);
    gameTitle.setFont(font);

    // Create Menu Options
    sf::Text playButton;
    playButton.setColor(sf::Color::White);
    playButton.setCharacterSize(70);
    playButton.setString("Play");
    playButton.setPosition(100, 200);
    playButton.setFont(font);

    sf::Text authorsButton;
    authorsButton.setColor(sf::Color::White);
    authorsButton.setCharacterSize(70);
    authorsButton.setString("Authors");
    authorsButton.setPosition(100, 300);
    authorsButton.setFont(font);

    sf::Text exitButton;
    exitButton.setColor(sf::Color::White);
    exitButton.setCharacterSize(70);
    exitButton.setString("Exit");
    exitButton.setPosition(100, 400);
    exitButton.setFont(font);
    
    while (window.isOpen()) {

        // Back to normal font size when menu option is not choosed
        playButton.setCharacterSize(70);
        authorsButton.setCharacterSize(70);
        exitButton.setCharacterSize(70);

        // Position of mouse
        sf::Vector2i position = sf::Mouse::getPosition(window);

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

        // Mouse Button pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // Play button clicked
            if (position.x >= 100 && position.x < 250 && position.y >= 200 && position.y < 280) {
                // Play
                return 1;
            }
            if (position.x >= 100 && position.x < 360 && position.y >= 300 && position.x < 380) {
                // Authors 
            }
            if (position.x >= 100 && position.x < 250 && position.y >= 400 && position.x < 480) {
                // Exit
                return (-1);
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Changing the size of the choosed menu option
        if (position.x >= 100 && position.x < 250 &&
            position.y >= 200 && position.y < 280) {
            playButton.setCharacterSize(90);
        }
        if (position.x >= 100 && position.x < 360 &&
            position.y >= 300 && position.y < 380) {
            authorsButton.setCharacterSize(90);
        }
        if (position.x >= 100 && position.x < 250 &&
            position.y >= 400 && position.y < 480) {
            exitButton.setCharacterSize(90);
        }

        // Draw 
        window.draw(gameTitle);
        window.draw(playButton);
        window.draw(authorsButton);
        window.draw(exitButton);
        
        // Update the window
        window.display();       
    }
    return (-1);
}