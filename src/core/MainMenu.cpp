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
    playing = false;
}

MainMenu::~MainMenu() {
}

int MainMenu::run(sf::RenderWindow& window) {

    // Set mouse position
    sf::Mouse::setPosition(sf::Vector2i(600, 600), window);
   
    // Load font
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        return(-1);
    }

    // Create Game Title
    sf::Text gameTitle;
    gameTitle.setColor(sf::Color::White);
    gameTitle.setCharacterSize(100);
    gameTitle.setString("Counter Strike 2D");
    gameTitle.setPosition(100,50);
    gameTitle.setFont(font);

    // Create Menu Options
    sf::Text play;
    play.setColor(sf::Color::White);
    play.setCharacterSize(70);
    play.setString("Play");
    play.setPosition(100, 200);
    play.setFont(font);

    sf::Text authors;
    authors.setColor(sf::Color::White);
    authors.setCharacterSize(70);
    authors.setString("Authors");
    authors.setPosition(100, 300);
    authors.setFont(font);

    sf::Text exit;
    exit.setColor(sf::Color::White);
    exit.setCharacterSize(70);
    exit.setString("Exit");
    exit.setPosition(100, 400);
    exit.setFont(font);
    
    // Create menu buttons
    sf::RectangleShape rectanglePlay;
    rectanglePlay.setSize(sf::Vector2f(150, 80));
    rectanglePlay.setOutlineColor(sf::Color::Red);
    rectanglePlay.setFillColor(sf::Color::Black);
    rectanglePlay.setOutlineThickness(5);
    rectanglePlay.setPosition(100, 200);

    while (window.isOpen()) {

        // Position of mouse
        sf::Vector2i position = sf::Mouse::getPosition(window);
        cout << position.x << " " << position.y << endl;

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
            if (position.x >= 100 && position.x < 250 && 
                position.y >= 200 && position.y < 280) {
                    return 1;
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw 
        window.draw(gameTitle);
        window.draw(rectanglePlay);
        window.draw(play);
        window.draw(authors);
        window.draw(exit);
        
        // Update the window
        window.display();       
    }
    return (-1);
}