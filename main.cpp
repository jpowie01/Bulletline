#include <iostream>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include "Obstacle.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "LevelOne.hpp"
#include "Screen.hpp"
#include "Game.hpp"

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

    return EXIT_SUCCESS;
}
