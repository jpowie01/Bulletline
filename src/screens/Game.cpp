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
    // Load background
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/defaultbackground.jpg")) {
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
    Label* threeText = new Label("3", 64, 0, 0);
    float threeWidth = threeText->getWidth();
    float threeHeight = threeText->getHeight();
    threeText->setPosition(((SCREEN_WIDTH - threeWidth) / 2), (SCREEN_HEIGHT - threeHeight) / 2);
    
    // '2' text
    Label* twoText = new Label("2", 84, 0, 0);
    float twoWidth = twoText->getWidth();
    float twoHeight = twoText->getHeight();
    twoText->setPosition(((SCREEN_WIDTH - twoWidth) / 2), (SCREEN_HEIGHT - twoHeight) / 2);
    
    // '1' text
    Label* oneText = new Label("1", 104, 0, 0);
    float oneWidth = oneText->getWidth();
    float oneHeight = oneText->getHeight();
    oneText->setPosition(((SCREEN_WIDTH - oneWidth) / 2), (SCREEN_HEIGHT - oneHeight) / 2);
    
    // 'START' text
    Label* startText = new Label("START!", 124, 0, 0);
    float startWidth = startText->getWidth();
    float startHeight = startText->getHeight();
    startText->setPosition(((SCREEN_WIDTH - startWidth) / 2), (SCREEN_HEIGHT - startHeight) / 2);

    // Prepare clock
    sf::Clock clock;
    
    // Print '3'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        threeText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print '2'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        twoText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print '1'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        oneText->draw(window);
        window.display();
    }
    clock.restart();
    
    // Print 'START'
    while (clock.getElapsedTime().asSeconds() < 1.0f) {
        window.clear(sf::Color::Black);
        startText->draw(window);
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
    Label* healthText = new Label(Converter::int2string(player->getHealth()), 36, 80, 618);
    /*sf::Text healthText;
    healthText.setString(Converter::int2string(player->getHealth()));
    healthText.setFont(arial);
    healthText.setPosition(80, 618);
    healthText.setCharacterSize(36);*/

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
            player->shot((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y);
        }

        // Update the whole map
        levelOne->update();
        
        // Update GUI
        healthText->setString(Converter::int2string(player->getHealth()));

        // Clear screen
        window.clear(sf::Color::White);

        // Draw map (level one)
        levelOne->draw(window);
        
        // Draw GUI
        window.draw(heartSprite);
        healthText->draw(window);

        // Update the window
        window.display();
    }

    // Release memory
    delete levelOne;

    // Change screen
    return EXIT;
}

void Game::after(sf::RenderWindow &window) {}
