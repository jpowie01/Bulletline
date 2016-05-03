/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#include "AuthorsMenu.hpp"

using namespace std;

//================================================================================
// Contructors
//================================================================================

AuthorsMenu::AuthorsMenu() {}

AuthorsMenu::~AuthorsMenu() {}

//================================================================================
// Core
//================================================================================

void AuthorsMenu::before(sf::RenderWindow &window) {}

int AuthorsMenu::run(sf::RenderWindow &window) {

    // Load font
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Failed to load font file (Arial.ttf)");
        return (-1);
    }

    // Create Menu Title
    sf::Text authorsTitle;
    authorsTitle.setColor(sf::Color::White);
    authorsTitle.setCharacterSize(100);
    authorsTitle.setString("Authors");
    authorsTitle.setPosition(100, 50);
    authorsTitle.setFont(font);

    // Authors names
    sf::Text author1;
    author1.setColor(sf::Color::White);
    author1.setCharacterSize(80);
    author1.setString(AUTHOR_1);
    author1.setPosition(100, 200);
    author1.setFont(font);

    sf::Text author2;
    author2.setColor(sf::Color::White);
    author2.setCharacterSize(80);
    author2.setString(AUTHOR_2);
    author2.setPosition(100, 300);
    author2.setFont(font);

    // Back button
    sf::Text backButton;
    backButton.setColor(sf::Color::White);
    backButton.setCharacterSize(70);
    backButton.setString("Back");
    backButton.setPosition(50, 580);
    backButton.setFont(font);

    while (window.isOpen()) {

        // Normal font size when menu option is not choosed
        backButton.setCharacterSize(70);

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

        // Mouse button pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // Back button clicked
            if (position.x >= 50 && position.x <= 210 && position.y >= 580 && position.y < 660) {
                // Back to main menu
                return MAIN_MENU;
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Changing the size of the back button
        if (position.x >= 50 && position.x <= 210 && position.y >= 580 & position.y < 660) {
            backButton.setCharacterSize(90);
        }

        // Draw
        window.draw(authorsTitle);
        window.draw(author1);
        window.draw(author2);
        window.draw(backButton);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void AuthorsMenu::after(sf::RenderWindow &window) {}