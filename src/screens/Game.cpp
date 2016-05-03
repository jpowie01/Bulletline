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

void Game::before(sf::RenderWindow &window) {
    // Load font
    sf::Font arial;
    if (!arial.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Error loading font (Arial.ttf)!\n");
        return;
    }
    
    // '3' text
    sf::Text threeText;
    threeText.setString("3");
    threeText.setFont(arial);
    threeText.setCharacterSize(64);
    threeText.setPosition((SCREEN_WIDTH - threeText.getLocalBounds().width)/2, (SCREEN_HEIGHT - threeText.getLocalBounds().height)/2);
    
    // '2' text
    sf::Text twoText;
    twoText.setString("2");
    twoText.setFont(arial);
    twoText.setCharacterSize(84);
    twoText.setPosition((SCREEN_WIDTH - twoText.getLocalBounds().width)/2, (SCREEN_HEIGHT - twoText.getLocalBounds().height)/2);
    
    // '1' text
    sf::Text oneText;
    oneText.setString("1");
    oneText.setFont(arial);
    oneText.setCharacterSize(104);
    oneText.setPosition((SCREEN_WIDTH - oneText.getLocalBounds().width)/2, (SCREEN_HEIGHT - oneText.getLocalBounds().height)/2);
    
    // 'START' text
    sf::Text startText;
    startText.setString("START!");
    startText.setFont(arial);
    startText.setCharacterSize(124);
    startText.setPosition((SCREEN_WIDTH - startText.getLocalBounds().width)/2, (SCREEN_HEIGHT - startText.getLocalBounds().height)/2);
    
    // Prepare clock
    sf::Clock clock;
    
    // Print '3'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(threeText);
        window.display();
    }
    clock.restart();
    
    // Print '2'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(twoText);
        window.display();
    }
    clock.restart();
    
    // Print '1'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(oneText);
        window.display();
    }
    clock.restart();
    
    // Print 'START'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        window.draw(startText);
        window.display();
    }
    clock.restart();
}

int Game::run(sf::RenderWindow& window) {
    // Create first map - level one
    LevelOne* levelOne = new LevelOne();
    
    // Create player
    Player* player = new Player(true, PLAYER_STARTING_POSITION_X, PLAYER_STARTING_POSITION_Y, levelOne);
    
    // Add player into map
    levelOne->addPlayer(player);
    
    // Load font
    sf::Font arial;
    if (!arial.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Error loading font (Arial.ttf)!\n");
        return -1;
    }
    
    // Heart sprite
    sf::Texture heartTexture;
    if (!heartTexture.loadFromFile(resourcePath() + "assets/images/heart.png")) {
        printf("Error loading heart texture (heart.png)!\n");
        return -1;
    }
    sf::Sprite heartSprite(heartTexture);
    heartSprite.setPosition(30, 620);
    
    // Health text
    sf::Text healthText;
    healthText.setString(Converter::int2string(player->getHealth()));
    healthText.setFont(arial);
    healthText.setPosition(80, 618);
    healthText.setCharacterSize(36);

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
            player->shot(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        }

        // Update the whole map
        levelOne->update();
        
        // Update GUI
        healthText.setString(Converter::int2string(player->getHealth()));

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        levelOne->draw(window);
        
        // Draw GUI
        window.draw(heartSprite);
        window.draw(healthText);

        // Update the window
        window.display();
    }

    // Release memory
    delete levelOne;

    // Change screen
    return EXIT;
}

void Game::after(sf::RenderWindow &window) {}
