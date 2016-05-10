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
    Label* authorsMenuTitle = new Label("Authors", 100, 100, 50, sf::Color::White);

    // Authors names
    Label* author1 = new Label(AUTHOR_1, 80, 100, 200, sf::Color::White);
    Label* author2 = new Label(AUTHOR_2, 80, 100, 300, sf::Color::White);

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
        authorsMenuTitle->draw(window);
        author1->draw(window);
        author2->draw(window);
        backButton->draw(window);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void AuthorsMenu::after(sf::RenderWindow &window) {}