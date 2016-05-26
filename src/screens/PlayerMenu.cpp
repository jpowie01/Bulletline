/*
* Counter Strike 2D
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
    // Creating background
    sf::Sprite background(commonData->defaultBackgroundTexture);

    // Creating Menu Title
    Label* playerMenuTitle = new Label("Player menu", 100, 370, 50, commonData);

    // Creating labels
    Label* address = new Label("IP address: ", 50, 150, 250, commonData);
    Label* port = new Label("Port: ", 50, 150, 330, commonData);
    Label* name = new Label("Name: ", 50, 150, 410, commonData);
    
    // Creating textField
    TextField* addressTextField = new TextField(400, 250,commonData);
    TextField* portTextField = new TextField(400, 330, commonData);
    TextField* nameTextField = new TextField(400, 410, commonData);
    string addressString = "";
    string portString = "";
    string nameString = "";

    // Creating next and back button
    Button* backButton = new Button("Back", 70, 50, 580, commonData);
    Button* nextButton = new Button("Next", 70, SCREEN_WIDTH - 150, 580, commonData);

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
                    }
                    else {
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
                    }
                    else {
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
                    }
                    else {
                        nameString += static_cast<char>(event.text.unicode);
                    }
                    nameTextField->setText(nameString);
                }
            }

            // Mouse Button pressed and cursor was in range of the text field
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (addressTextField->cursorInRange(position) == true) {
                    // Changing outline of text field indicating text field is ready for input
                    addressTextField->setOutline(sf::Color::Red);
                    addressTextField->m_inputFlag = true;
                }
                else {
                    // Clicking anywhere but text field will disable it
                    addressTextField->m_inputFlag = false;
                    addressTextField->setOutline(sf::Color::Black);
                }
                if (portTextField->cursorInRange(position) == true) {
                    portTextField->setOutline(sf::Color::Red);
                    portTextField->m_inputFlag = true;
                }
                else {
                    portTextField->m_inputFlag = false;
                    portTextField->setOutline(sf::Color::Black);
                }
                if (nameTextField->cursorInRange(position) == true) {
                    nameTextField->setOutline(sf::Color::Red);
                    nameTextField->m_inputFlag = true;
                }
                else {
                    nameTextField->m_inputFlag = false;
                    nameTextField->setOutline(sf::Color::Black);
                }
            }
        }

        // Mouse Button pressed and cursor was in range of the button
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (backButton->cursorInRange(position) == true) {
                return MAIN_MENU;
            }
            if (nextButton->cursorInRange(position) == true) {
                return WAITING_MENU;
            }
        }
        else {
            // Changing the color of the button if cursor is in range
            if (backButton->cursorInRange(position) == true) {
                backButton->changeColor(sf::Color::Red);
            }
            else {
                backButton->setDefaultColor();
            }
            if (nextButton->cursorInRange(position) == true) {
                nextButton->changeColor(sf::Color::Red);
            }
            else {
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