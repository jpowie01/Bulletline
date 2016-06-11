/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerMenu.hpp"

//================================================================================
// Contructors
//================================================================================

PlayerMenu::PlayerMenu() {}

PlayerMenu::~PlayerMenu() {}

//================================================================================
// Core
//================================================================================

void PlayerMenu::before(sf::RenderWindow &window, CommonData* commonData) {}

int PlayerMenu::run(sf::RenderWindow &window, CommonData* commonData) {
    // Create background
    sf::Sprite background(commonData->defaultBackgroundTexture);
    
    // Prepare temporary UI data
    string addressString = SERVER_HOST;
    string portString = Converter::int2string(SERVER_PORT);
    string nameString = "";

    // Create menu title
    Label* playerMenuTitle = new Label("Player menu", 100, commonData);
    playerMenuTitle->setPosition((SCREEN_WIDTH - playerMenuTitle->getWidth()) / 2, 50);

    // Create labels
    Label* address = new Label("IP address: ", 50, 150, 250, commonData);
    Label* port = new Label("Port: ", 50, 150, 330, commonData);
    Label* name = new Label("Name: ", 50, 150, 410, commonData);
    
    // Create text fields
    TextField* addressTextField = new TextField(400, 250, commonData);
    TextField* portTextField = new TextField(400, 330, commonData);
    TextField* nameTextField = new TextField(400, 410, commonData);

    // Default values
    addressTextField->setText(addressString);
    portTextField->setText(portString);
    nameTextField->setText(nameString);

    // Create buttons
    Button* backButton = new Button("Back", 70, BUTTON_POSITION_X, BUTTON_POSITION_Y, commonData);
    Button* nextButton = new Button("Next", 70, NEXT_BUTTON_POSITION_X, BUTTON_POSITION_Y, commonData);

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

            // Text entered event
            if (addressTextField->m_inputFlag == true && event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8) {
                        if (strcmp(addressString.c_str(), "") != 0) {
                            addressString.pop_back();
                        }
                    } else {
                        addressString += static_cast<char>(event.text.unicode);
                    }
                    addressTextField->setText(addressString);
                }
            }
            if (portTextField->m_inputFlag == true && event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8) {
                        if (strcmp(portString.c_str(), "") != 0) {
                            portString.pop_back();
                        }
                    } else {
                        portString += static_cast<char>(event.text.unicode);
                    }
                    portTextField->setText(portString);
                }
            }
            if (nameTextField->m_inputFlag == true && event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    if (event.text.unicode == 8) {
                        if (strcmp(nameString.c_str(), "") != 0) {
                            nameString.pop_back();
                        }
                    } else {
                        nameString += static_cast<char>(event.text.unicode);
                    }
                    nameTextField->setText(nameString);
                }
            }

            // Mouse Button pressed and cursor  in range of the text field
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (addressTextField->cursorInRange(position) == true) {
                    // Changing outline of text field indicating text field is ready for input
                    addressTextField->setOutline(sf::Color::Red);
                    addressTextField->m_inputFlag = true;
                } else {
                    // Clicking anywhere but text field will disable it
                    addressTextField->m_inputFlag = false;
                    addressTextField->setOutline(sf::Color::Black);
                }
                if (portTextField->cursorInRange(position) == true) {
                    portTextField->setOutline(sf::Color::Red);
                    portTextField->m_inputFlag = true;
                } else {
                    portTextField->m_inputFlag = false;
                    portTextField->setOutline(sf::Color::Black);
                }
                if (nameTextField->cursorInRange(position) == true) {
                    nameTextField->setOutline(sf::Color::Red);
                    nameTextField->m_inputFlag = true;
                } else {
                    nameTextField->m_inputFlag = false;
                    nameTextField->setOutline(sf::Color::Black);
                }
            }
        }

        // Mouse Button pressed and cursor in range of the button
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (backButton->cursorInRange(position) == true) {
                return MAIN_MENU;
            }
            if (nextButton->cursorInRange(position) == true) {
                // Save data
                commonData->serverAddress = sf::IpAddress(addressTextField->getText());
                commonData->serverPort = Converter::string2int(portTextField->getText());
                commonData->playerName = nameTextField->getText();
                
                // Create server connection
                commonData->server = new Connection(commonData->serverAddress, commonData->serverPort, commonData);
                
                // Prepare server connection thread
                commonData->serverThread = new sf::Thread(&Connection::run, commonData->server);
                commonData->serverThread->launch();
                
                // Prepare game to start
                commonData->prepareGameToStart();
                
                // Save data
                commonData->mainPlayer->setName(commonData->playerName);
                
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
                return WAITING_MENU;
            }
        } else {
            // Changing the color of the button if cursor is in range
            if (backButton->cursorInRange(position) == true) {
                backButton->changeColor(sf::Color::Red);
            } else {
                backButton->setDefaultColor();
            }
            if (nextButton->cursorInRange(position) == true) {
                nextButton->changeColor(sf::Color::Red);
            } else {
                nextButton->setDefaultColor();
            }
        }

        // Clear screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(background);
        playerMenuTitle->draw(window);
        address->draw(window);
        port->draw(window);
        name->draw(window);
        addressTextField->draw(window);
        portTextField->draw(window);
        nameTextField->draw(window);
        backButton->draw(window);
        nextButton->draw(window);

        // Update the window
        window.display();
    }

    // Change screen
    return EXIT;
}

void PlayerMenu::after(sf::RenderWindow &window, CommonData *commonData) {}
