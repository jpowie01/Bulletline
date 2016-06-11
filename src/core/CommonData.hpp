/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef CommonData_hpp
#define CommonData_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Map.hpp"
#include "Player.hpp"
#include "../levels/LevelOne.hpp"
#include "../helpers/ResourcePath.hpp"

class Connection;

using namespace std;

class CommonData {
public:
    // Constructors
    CommonData();
    ~CommonData();

    // Main data
    Map* map;
    Player* mainPlayer;
    int winningTeam;
    string playerName;
    
    // Server data
    Connection* server;
    sf::Thread* serverThread;
    sf::IpAddress serverAddress;
    short serverPort;

    // Game flags
    bool joinedGame = false;
    bool gameStarted = false;
    bool gameEnded = false;

    // Fonts
    sf::Font arialFont;
    sf::Font bebasNeueFont;
    sf::Texture mainMenuBackgroundTexture;
    sf::Texture defaultBackgroundTexture;
    sf::Texture gameBackground;
    sf::Texture heartTexture;

    // Methods
    void loadFonts();
    void loadTextures();
    void prepareGameToStart();
    void prepareGameToRestart();
};

#endif
