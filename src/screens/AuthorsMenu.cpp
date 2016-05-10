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
    Button* backButton = new Button("Back", 70, 80, 50, 580, sf::Color::White);

    while (window.isOpen()) {
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

        // Mouse Button pressed and cursor was in range of the button
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (backButton->cursorInRange(position, 50, 210, 580, 660) == true) {
                return MAIN_MENU;
            }
        } else {
            // Changing the size of the button if cursor is in range
            backButton->cursorInRange(position, 50, 210, 580, 660);
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(authorsTitle);
        window.draw(author1);
        window.draw(author2);
        backButton->draw(window);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void AuthorsMenu::after(sf::RenderWindow &window) {}