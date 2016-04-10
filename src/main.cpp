/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "core/Obstacle.hpp"
#include "core/Player.hpp"
#include "core/Map.hpp"
#include "core/Screen.hpp"
#include "core/Game.hpp"
#include "levels/LevelOne.hpp"

#include "helpers/ResourcePath.hpp"

int main(int, char const**)
{
    // Create screens
    vector <Screen*> screens;
    int screen = 0;

    // Window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 680), "CS 1.5 Alpha", sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);

    // Screens preparations
    Game* game = new Game();
    screens.push_back(game);

    //  Main loop
    while (screen >= 0) {
        screen = screens[screen]->run(window);
    }

    // Exit game
    return EXIT_SUCCESS;
}
