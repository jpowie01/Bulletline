/*
 * Bulletline
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
    
    // Overlay
    sf::RectangleShape overlay;
    overlay.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    overlay.setFillColor(sf::Color(0, 0, 0, 70));

    // Dead label
    Label* deadLabel = new Label("You're DEAD!", 64, commonData);
    deadLabel->setPosition((int)(SCREEN_WIDTH - deadLabel->getWidth())/2, (int)(SCREEN_HEIGHT - deadLabel->getHeight())/2 - 30);
    Label* deadInformationLabel = new Label("Wait until the game has ended...", 30, commonData);
    deadInformationLabel->setPosition((int)(SCREEN_WIDTH - deadInformationLabel->getWidth())/2, SCREEN_HEIGHT - 70);

    // Team win label
    Label* redTeamWinLabel = new Label("RED TEAM WIN", 80, commonData);
    redTeamWinLabel->setColor(sf::Color::Red);
    redTeamWinLabel->setPosition((int)(SCREEN_WIDTH - redTeamWinLabel->getWidth())/2, (int)(SCREEN_HEIGHT - redTeamWinLabel->getHeight())/2 - 30);
    Label* blueTeamWinLabel = new Label("BLUE TEAM WIN", 80, commonData);
    blueTeamWinLabel->setColor(sf::Color::Blue);
    blueTeamWinLabel->setPosition((int)(SCREEN_WIDTH - blueTeamWinLabel->getWidth())/2, (int)(SCREEN_HEIGHT - blueTeamWinLabel->getHeight())/2 - 30);
    
    // Restart button
    Button* restartButton = new Button("Play again!", 48, commonData);
    restartButton->setPosition((int)(SCREEN_WIDTH - restartButton->getWidth())/2, SCREEN_HEIGHT - 200);

    // Start the game loop
    while (window.isOpen())
    {
        // Position of mouse
        sf::Vector2i position = sf::Mouse::getPosition(window);
        
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

        // Refresh game only when game is on
        if (!commonData->gameEnded) {
            // Update the whole map
            commonData->map->update();

            // Send player update
            commonData->server->sendPlayerUpdate(commonData->mainPlayer);
        }
        
        // Update GUI
        if (commonData->gameEnded && commonData->mainPlayer->getTeamID() != commonData->winningTeam) {
            // Just to be sure that there won't be race between updating player data and end of the game
            healthText->setString("0");
        } else {
            healthText->setString(Converter::int2string(commonData->mainPlayer->getHealth()));
        }
        
        // Check restart button state
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (commonData->gameEnded && restartButton->cursorInRange(position)) {
                // Prepare to restart
                commonData->prepareGameToRestart();
                
                // Send introduction to the server
                commonData->server->sendPlayerIntroduction(commonData->mainPlayer);
                
                // Create background
                sf::Sprite background(commonData->defaultBackgroundTexture);
                
                // Create menu title
                Label* waitingForServerResponseLabel = new Label("Waiting for server response...", 50, commonData);
                int x = (SCREEN_WIDTH - waitingForServerResponseLabel->getWidth()) / 2;
                int y = (SCREEN_HEIGHT - waitingForServerResponseLabel->getHeight()) / 2;
                waitingForServerResponseLabel->setPosition(x, y);
                
                // Wait for response with confirmation
                while (!commonData->joinedGame) {
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
                    waitingForServerResponseLabel->draw(window);
                    
                    // Update the window
                    window.display();
                }
                
                // Go to lobby
                return WAITING_MENU;
            }
        }
        
        // Changing the color of the button if cursor is in range
        if (commonData->gameEnded) {
            if (restartButton->cursorInRange(position)) {
                restartButton->changeColor(sf::Color::Red);
            } else {
                restartButton->setDefaultColor();
            }
        }

        // Clear screen
        window.clear();

        // Draw map (level one)
        commonData->map->draw(window);
        
        // Draw GUI
        window.draw(heartSprite);
        healthText->draw(window);

        // Overlay screens
        if (commonData->gameEnded) {
            window.draw(overlay);
            if (commonData->winningTeam == RED_TEAM) {
                redTeamWinLabel->draw(window);
            } else {
                blueTeamWinLabel->draw(window);
            }
            restartButton->draw(window);
        } else if (commonData->mainPlayer->isDead()) {
            window.draw(overlay);
            deadLabel->draw(window);
            deadInformationLabel->draw(window);
        }

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void Game::after(sf::RenderWindow &window, CommonData* commonData) {}
