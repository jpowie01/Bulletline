/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Game.hpp"

//================================================================================
// Contructors
//================================================================================

Game::Game() {}

Game::~Game() {}

//================================================================================
// Core
//================================================================================

void Game::before(sf::RenderWindow &window, CommonData* commonData) {
    // Prepare players and set their colors
    for (int i = 0; i < commonData->map->playersSize(); i++) {
        Player* player = commonData->map->getPlayerAtIndex(i);
        if (player->getTeamID() == BLUE_TEAM) {
            player->setColor(sf::Color::Blue);
        } else {
            player->setColor(sf::Color::Red);
        }
    }

    // Create background
    sf::Sprite background(commonData->defaultBackgroundTexture);
    background.setPosition(0, 0);
    
    // '3' text
    Label* threeText = new Label("3", 64, 0, 0, commonData);
    float threeWidth = threeText->getWidth();
    float threeHeight = threeText->getHeight();
    threeText->setPosition((int)((SCREEN_WIDTH - threeWidth) / 2), (int)(SCREEN_HEIGHT - threeHeight) / 2);
    
    // '2' text
    Label* twoText = new Label("2", 84, 0, 0, commonData);
    float twoWidth = twoText->getWidth();
    float twoHeight = twoText->getHeight();
    twoText->setPosition((int)((SCREEN_WIDTH - twoWidth) / 2), (int)(SCREEN_HEIGHT - twoHeight) / 2);
    
    // '1' text
    Label* oneText = new Label("1", 104, 0, 0, commonData);
    float oneWidth = oneText->getWidth();
    float oneHeight = oneText->getHeight();
    oneText->setPosition((int)((SCREEN_WIDTH - oneWidth) / 2), (int)(SCREEN_HEIGHT - oneHeight) / 2);
    
    // 'START' text
    Label* startText = new Label("START!", 124, 0, 0, commonData);
    float startWidth = startText->getWidth();
    float startHeight = startText->getHeight();
    startText->setPosition((int)((SCREEN_WIDTH - startWidth) / 2), (int)(SCREEN_HEIGHT - startHeight) / 2);

    // Prepare clock
    sf::Clock clock;
    
    // Print series of labels
    for (int textNumber = 3; textNumber >= 0; textNumber--) {
        // Display each label for one second
        while (clock.getElapsedTime().asSeconds() < 1.0f) {
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

            // Clear window
            window.clear(sf::Color::Black);

            // Draw
            switch (textNumber) {
                case 3:
                    threeText->draw(window);
                    break;
                case 2:
                    twoText->draw(window);
                    break;
                case 1:
                    oneText->draw(window);
                    break;
                case 0:
                    startText->draw(window);
                    break;
                default:
                    break;
            }

            // Display on screen
            window.display();
        }

        // Restart one second clock
        clock.restart();
    }
}

int Game::run(sf::RenderWindow& window, CommonData* commonData) {
    // Prepare heart sprite
    sf::Sprite heartSprite(commonData->heartTexture);
    heartSprite.setPosition(30, 620);

    // Health text
    Label* healthText = new Label(Converter::int2string(commonData->mainPlayer->getHealth()), 36, 80, 618, commonData);

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
            Bullet* bullet = commonData->mainPlayer->shot((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
            if (bullet != NULL) {
                commonData->server->sendPlayerShot(bullet);
            }
        }

        // Update the whole map
        commonData->map->update();

        // Send player update
        commonData->server->sendPlayerUpdate(commonData->mainPlayer);
        
        // Update GUI
        healthText->setString(Converter::int2string(commonData->mainPlayer->getHealth()));

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        commonData->map->draw(window);
        
        // Draw GUI
        window.draw(heartSprite);
        healthText->draw(window);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void Game::after(sf::RenderWindow &window, CommonData* commonData) {}
