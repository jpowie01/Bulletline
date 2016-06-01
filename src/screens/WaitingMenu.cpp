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

void WaitingMenu::before(sf::RenderWindow &window, CommonData* commonData) {
    // Create first map - level one
    commonData->map = new LevelOne();

    // Create player
    commonData->mainPlayer = new Player(true, PLAYER_STARTING_POSITION_X, PLAYER_STARTING_POSITION_Y, commonData->map);
    commonData->mainPlayer->setName(commonData->playerName);

    // Add player into map
    commonData->map->addPlayer(commonData->mainPlayer);
    
    // Create server connection
    commonData->server = new Connection(commonData->serverAddress, commonData->serverPort, commonData);
    
    // Prepare server connection thread
    commonData->serverThread = new sf::Thread(&Connection::run, commonData->server);
    commonData->serverThread->launch();
    
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
}

int WaitingMenu::run(sf::RenderWindow &window, CommonData* commonData) {
    // Create background
    sf::Sprite background(commonData->defaultBackgroundTexture);

    // Create menu title
    Label* lobbyTitle = new Label("Lobby", 100, commonData);
    lobbyTitle->setPosition((SCREEN_WIDTH - lobbyTitle->getWidth()) / 2, 50);

    // Teams labels
    Label* blueTeamLabel = new Label("Blue team", 70, 150, 200, commonData);
    blueTeamLabel->setColor(sf::Color::Blue);
    Label* redTeamLabel = new Label("Red team", 70, commonData);
    redTeamLabel->setPosition(SCREEN_WIDTH - redTeamLabel->getWidth() - 150, 200);
    redTeamLabel->setColor(sf::Color::Red);

    // Players labels
    Label** playerLabel = new Label*[4];
    for (int i = 0; i < 4; i++) {
        playerLabel[i] = new Label("", 60, 180, 300 + (i/2)*100, commonData);
        if (i % 2 == 1) {
            playerLabel[i]->setPosition(SCREEN_WIDTH - playerLabel[i]->getWidth() - 180, 300 + (i/2)*100);
        }
    }

    // Countdown label
    Label* countdownLabel = new Label("The game will start in 15 seconds...", 40, commonData);
    countdownLabel->setPosition(SCREEN_WIDTH - countdownLabel->getWidth() - 30, 600);

    // Countdown
    sf::Clock clock;
    sf::Time fiveteenSeconds = sf::seconds(15.0f);
    int amountOfPlayers = 0;

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

        // Show players name on labels
        for (int i = 0; i < commonData->map->playersSize(); i++) {
            Player* player = commonData->map->getPlayerAtIndex(i);
            playerLabel[player->getID()]->setString(player->getName());
        }

        // Prepare countdown information
        if ((amountOfPlayers != commonData->map->playersSize()) && (commonData->map->playersSize() == 2 || commonData->map->playersSize() == 4)) {
            clock.restart();
            amountOfPlayers = commonData->map->playersSize();
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(background);
        lobbyTitle->draw(window);
        blueTeamLabel->draw(window);
        redTeamLabel->draw(window);
        for (int i = 0; i < 4; i++) {
            if (i % 2 == 1) {
                playerLabel[i]->setPosition(SCREEN_WIDTH - playerLabel[i]->getWidth() - 180, 300 + (i/2)*100);
            }
            playerLabel[i]->draw(window);
        }

        // Show information about starting game only when there are 2 or 4 players
        if (commonData->map->playersSize() == 2 || commonData->map->playersSize() == 4) {
            int timeToStart = (int)ceil(fiveteenSeconds.asSeconds() - clock.getElapsedTime().asSeconds());
            if (timeToStart <= 3) {
                timeToStart = 3;
            }
            countdownLabel->setString("The game will start in " + Converter::int2string(timeToStart) + " seconds...");
            countdownLabel->setPosition(SCREEN_WIDTH - countdownLabel->getWidth() - 30, 600);
            countdownLabel->draw(window);
        }

        // Update the window
        window.display();

        // Go to the game if countdown will finish
        if ((amountOfPlayers == 2 || amountOfPlayers == 4) && clock.getElapsedTime().asSeconds() > fiveteenSeconds.asSeconds() - 3.0f && commonData->gameStarted == true) {
            return GAME;
        }
    }

    // Change screen
    return EXIT;
}

void WaitingMenu::after(sf::RenderWindow &window, CommonData* commonData) {}
