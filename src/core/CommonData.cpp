/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "CommonData.hpp"
#include "../network/Connection.hpp"

//================================================================================
// Constructors
//================================================================================

CommonData::CommonData() {
    serverThread = NULL;
    server = NULL;
    map = NULL;
    mainPlayer = NULL;
    this->loadFonts();
    this->loadTextures();
}

CommonData::~CommonData() {
    if (serverThread != NULL) serverThread->terminate();
    delete serverThread;
    delete server;
    delete map;
    delete mainPlayer;
}

//================================================================================
// Methods
//================================================================================

void CommonData::loadFonts() {
    // Load Arial font
    if (!this->arialFont.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Error loading font (Arial.ttf)!\n");
        return;
    }

    // Load Bebas Neue font
    if (!this->bebasNeueFont.loadFromFile(resourcePath() + "assets/fonts/BebasNeue.otf")) {
        printf("Failed to load font file (BebasNeue.otf)");
        return;
    }
}

void CommonData::loadTextures() {
    // Load main menu background
    if (!this->mainMenuBackgroundTexture.loadFromFile(resourcePath() + "assets/images/background.jpg")) {
        return;
    }

    // Load default background
    if (!this->defaultBackgroundTexture.loadFromFile(resourcePath() + "assets/images/defaultbackground.jpg")) {
        printf("Error loading heart texture (defaultbackground.png)!\n");
        return;
    }

    // Load in game backround
    if (!this->lvl1background.loadFromFile(resourcePath() + "assets/images/lvl1background-001.jpg")) {
        printf("Error loading heart texture (lvl1background.png)!\n");
        return;
    }

    // Heart texture
    if (!this->heartTexture.loadFromFile(resourcePath() + "assets/images/heart.png")) {
        printf("Error loading heart texture (heart.png)!\n");
        return;
    }
}

void CommonData::prepareGameToStart() {
    // Default flags
    joinedGame = false;
    gameStarted = false;
    gameEnded = false;
    
    // Create first map - level one
    this->map = new LevelOne();
    
    // Create player
    this->mainPlayer = new Player(true, PLAYER_STARTING_POSITION_X, PLAYER_STARTING_POSITION_Y, this->map);
    this->mainPlayer->setName(this->playerName);
    
    // Add player into map
    this->map->addPlayer(this->mainPlayer);
}

void CommonData::prepareGameToRestart() {
    // Remove data
    delete this->map;
    
    // Prepare game to start
    this->prepareGameToStart();
}
