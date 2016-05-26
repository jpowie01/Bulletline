/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#include "AuthorsMenu.hpp"

//================================================================================
// Contructors
//================================================================================

AuthorsMenu::AuthorsMenu() {}

AuthorsMenu::~AuthorsMenu() {}

//================================================================================
// Core
//================================================================================

void AuthorsMenu::before(sf::RenderWindow &window, CommonData* commonData) {}

int AuthorsMenu::run(sf::RenderWindow &window, CommonData* commonData) {
    // Create background
    sf::Sprite background(commonData->defaultBackgroundTexture);

    // Create menu title
    Label* authorsMenuTitle = new Label("Authors", 100, commonData);
    authorsMenuTitle->setPosition((SCREEN_WIDTH - authorsMenuTitle->getWidth()) / 2, 50);

    // Authors names
    Label* author1 = new Label(AUTHOR_1, 80, commonData);
    Label* author2 = new Label(AUTHOR_2, 80, commonData);
    author1->setPosition((SCREEN_WIDTH - author1->getWidth()) / 2, 200);
    author2->setPosition((SCREEN_WIDTH - author2->getWidth()) / 2, 300);

    // Back button
    Button* backButton = new Button("Back", 70, BUTTON_POSITION_X, BUTTON_POSITION_Y, commonData);

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

        // Mouse Button pressed and cursor in range of the button
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (backButton->cursorInRange(position) == true) {
                return MAIN_MENU;
            }
        } else {
            // Changing the color of the button if cursor is in range
            if (backButton->cursorInRange(position) == true) {
                backButton->changeColor(sf::Color::Red);
            } else {
                backButton->setDefaultColor();
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(background);
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

void AuthorsMenu::after(sf::RenderWindow &window, CommonData* commonData) {}
