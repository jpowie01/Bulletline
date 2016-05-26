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
    // Load background
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "assets/images/defaultbackground.jpg")) {
        printf("Error loading image (defaultbackground.jpg)!\n");
        return;
    }

    // Creating background
    sf::Sprite background(texture);
    background.setPosition(0, 0);

    // Load font
    sf::Font arial;
    if (!arial.loadFromFile(resourcePath() + "assets/fonts/BebasNeue.otf")) {
        printf("Error loading font (BebasNeue.otf)!\n");
        return;
    }
    
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
    
    // Print '3'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(background);
        threeText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print '2'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(background);
        twoText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print '1'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(background);
        oneText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print 'START'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(background);
        startText->draw(window);
        window.display();
    }
    clock.restart();
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
            commonData->mainPlayer->shot((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
        }

        // Update the whole map
        commonData->map->update();

        // Send player update
        //commonData->server->sendPlayerUpdate(commonData->mainPlayer);
        
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
