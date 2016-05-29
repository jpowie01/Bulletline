/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef CommonData_hpp
#define CommonData_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "Map.hpp"
#include "Player.hpp"
#include "../helpers/ResourcePath.hpp"

class Connection;

using namespace std;

class CommonData {
public:
    // Constructors
    CommonData();
    ~CommonData();

    // Main data
    Connection* server;
    sf::Thread* serverThread;
    Map* map;
    Player* mainPlayer;

    // Game flags
    bool joinedGame = false;
    bool gameStarted = false;

    // Fonts
    sf::Font arialFont;
    sf::Font bebasNeueFont;
    sf::Texture mainMenuBackgroundTexture;
    sf::Texture defaultBackgroundTexture;
    sf::Texture heartTexture;

    // Methods
    void loadFonts();
    void loadTextures();
};

#endif
