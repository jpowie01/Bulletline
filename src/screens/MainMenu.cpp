/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "MainMenu.hpp"

//================================================================================
// Contructors
//================================================================================

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

//================================================================================
// Core
//================================================================================

void MainMenu::before(sf::RenderWindow &window, CommonData* commonData) {}

int MainMenu::run(sf::RenderWindow& window, CommonData* commonData) {
    // Create background
    sf::Sprite background(commonData->mainMenuBackgroundTexture);

    // Create game title  
    Label* gameTitle = new Label(GAME_TITLE, 100, commonData);
    gameTitle->setPosition((SCREEN_WIDTH - gameTitle->getWidth()) / 2, 50);

    // Create menu buttons
    Button* playButton = new Button("Play", 70, commonData);
    Button* authorsButton = new Button("Authors", 70, commonData);
    Button* exitButton = new Button("Exit", 70, commonData);
    
    // Set buttons postions
    playButton->setPosition((SCREEN_WIDTH - playButton->getWidth()) / 2, 200);
    authorsButton->setPosition((SCREEN_WIDTH - authorsButton->getWidth()) / 2, 300);
    exitButton->setPosition((SCREEN_WIDTH - exitButton->getWidth()) / 2, 400);

    // Main loop
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
            if (playButton->cursorInRange(position) == true) {
                return PLAYER_MENU;
            }
            if (authorsButton->cursorInRange(position) == true) {
                return AUTHORS_MENU;
            }
            if (exitButton->cursorInRange(position) == true) {
                return EXIT;
            }
        } else {
            // Changing the color of the button if cursor is in range
            if (playButton->cursorInRange(position) == true) {
                playButton->changeColor(sf::Color::Red);
            } else {
                playButton->setDefaultColor();
            }
            if (authorsButton->cursorInRange(position) == true) {
                authorsButton->changeColor(sf::Color::Red);
            } else {
                authorsButton->setDefaultColor();
            }
            if (exitButton->cursorInRange(position) == true) {
                exitButton->changeColor(sf::Color::Red);
            } else {
                exitButton->setDefaultColor();
            }
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

void MainMenu::after(sf::RenderWindow &window, CommonData* commonData) {}
