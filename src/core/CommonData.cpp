//
//  CommonData.cpp
//  Przetwarzanie Rozproszone - Klient
//
//  Created by Jakub Powierza on 03/05/16.
//  Copyright © 2016 Jakub Powierza. All rights reserved.
//

#include "CommonData.hpp"
#include "../network/Connection.hpp"

CommonData::CommonData() {
    serverThread = NULL;
    server = NULL;
    map = NULL;
    mainPlayer = NULL;
}

CommonData::~CommonData() {
    if (serverThread != NULL) serverThread->terminate();
    delete serverThread;
    delete server;
    delete map;
    delete mainPlayer;
}

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

    // Heart texture
    if (!this->heartTexture.loadFromFile(resourcePath() + "assets/images/heart.png")) {
        printf("Error loading heart texture (heart.png)!\n");
        return;
    }
}
