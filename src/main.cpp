/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Definitions.hpp"
#include "core/Obstacle.hpp"
#include "core/Player.hpp"
#include "core/Map.hpp"
#include "core/Screen.hpp"
#include "levels/LevelOne.hpp"
#include "screens/Game.hpp"
#include "screens/MainMenu.hpp"
#include "screens/AuthorsMenu.hpp"
#include "core/CommonData.hpp"

int main(int, char const**)
{
    // Screens table
    Screen* screens[NUMBER_OF_SCREENS];
    int screenNumber = STARTING_SCREEN;

    // Window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = ANTIALIASING_LEVEL;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE, sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);

    // Create screens
    MainMenu* mainMenu = new MainMenu();
    Game* game = new Game();
    AuthorsMenu* authorsMenu = new AuthorsMenu();

    // Add screens to table
    screens[MAIN_MENU] = mainMenu;
    screens[GAME] = game;
    screens[AUTHORS_MENU] = authorsMenu;

    // Create common data
    CommonData* commonData = new CommonData();
    commonData->loadFonts();
    commonData->loadTextures();

    //  Main loop
    while (screenNumber >= 0) {
        // Do everything before
        screens[screenNumber]->before(window, commonData);
        
        // Run screen
        int newScreenNumber = screens[screenNumber]->run(window, commonData);
        
        // Do everything after
        screens[screenNumber]->after(window, commonData);
        
        // Change screen
        screenNumber = newScreenNumber;
    }

    // Release memory
    delete commonData;

    // Exit game
    return EXIT_SUCCESS;
}
