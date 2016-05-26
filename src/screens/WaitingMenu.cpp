/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#include "WaitingMenu.hpp"

using namespace std;

//================================================================================
// Contructors
//================================================================================

WaitingMenu::WaitingMenu() {}

WaitingMenu::~WaitingMenu() {}

//================================================================================
// Core
//================================================================================

void WaitingMenu::before(sf::RenderWindow &window, CommonData* commonData) {}

int WaitingMenu::run(sf::RenderWindow &window, CommonData* commonData) {
    // Create background
    sf::Sprite background(commonData->defaultBackgroundTexture);

    // Create Menu Title
    Label* lobbyTitle = new Label("Lobby", 100, 500, 50, commonData);

    // Teams labels
    Label* blueTeamLabel = new Label("Blue team", 70, 120, 200, commonData);
    blueTeamLabel->setColor(sf::Color::Blue);
    Label* redTeamLabel = new Label("Red team", 70, 870, 200, commonData);
    redTeamLabel->setColor(sf::Color::Red);

    // Players labels
    Label* playerOneLabel = new Label("Player 1", 60, 150, 300, commonData);
    Label* playerTwoLabel = new Label("A", 60, 900, 300, commonData);
    Label* playerThreeLabel = new Label("Player 3", 60, 150, 400, commonData);
    Label* playerFourLabel = new Label("Player 43210", 60, 900, 400, commonData);

    // Information label
    Label* infoLabel = new Label("The game will start in x seconds!", 40, 700, 600, commonData);

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

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(background);
        lobbyTitle->draw(window);
        blueTeamLabel->draw(window);
        redTeamLabel->draw(window);
        playerOneLabel->draw(window);
        playerTwoLabel->draw(window);
        playerThreeLabel->draw(window);
        playerFourLabel->draw(window);
        infoLabel->draw(window);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void WaitingMenu::after(sf::RenderWindow &window, CommonData* commonData) {}
