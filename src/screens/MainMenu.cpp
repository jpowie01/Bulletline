/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "MainMenu.hpp"

using namespace std;

//================================================================================
// Contructors
//================================================================================

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

//================================================================================
// Core
//================================================================================

void MainMenu::before(sf::RenderWindow &window) {}

int MainMenu::run(sf::RenderWindow& window) {
    // Load background
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/background.jpg")) {
        return (-1);
    }

    // Creating background
    sf::Sprite background(texture);
    background.setPosition(0, 0);

    // Load font
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "assets/fonts/BebasNeue.otf")) {
        printf("Failed to load font file (BebasNeue.otf)");
        return (-1);
    }

    // Create Game Title
    Label* gameTitle = new Label(GAME_TITLE, 100, 300, 50, sf::Color::White);

    // Create Menu Options
    Button* playButton = new Button("Play", 70, 90, 535, 200, sf::Color::White);
    Button* authorsButton = new Button("Authors", 70, 90, 485, 300, sf::Color::White);
    Button* exitButton = new Button("Exit", 70, 90, 535, 400, sf::Color::White);
    
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
            if (playButton->cursorInRange(position, 535, 685, 200, 280) == true) {
                return GAME;
            }
            if (authorsButton->cursorInRange(position, 485, 645, 300, 380) == true) {
                return AUTHORS_MENU;
            }
            if (exitButton->cursorInRange(position, 535, 685, 400, 480) == true) {
                return EXIT;
            }
        } else {
            // Changing the color of the button if cursor is in range
            playButton->cursorInRange(position, 535, 685, 200, 280);
            authorsButton->cursorInRange(position, 485, 645, 300, 380);
            exitButton->cursorInRange(position, 535, 685, 400, 480);
        }
   
        // Clear screen
        window.clear(sf::Color::Black);

        // Draw 
        window.draw(background);
        gameTitle->draw(window);
        playButton->draw(window);
        authorsButton->draw(window);
        exitButton->draw(window);
        
        // Update the window
        window.display();       
    }
    
    // Change screen
    return EXIT;
}

void MainMenu::after(sf::RenderWindow &window) {}
