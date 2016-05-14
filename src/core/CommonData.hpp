//
//  CommonData.hpp
//  Przetwarzanie Rozproszone - Klient
//
//  Created by Jakub Powierza on 03/05/16.
//  Copyright © 2016 Jakub Powierza. All rights reserved.
//

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
    CommonData();
    ~CommonData();

    Connection* server;
    sf::Thread* serverThread;

    Map* map;
    Player* mainPlayer;

    sf::Font arialFont;
    sf::Font bebasNeueFont;
    sf::Texture mainMenuBackgroundTexture;
    sf::Texture defaultBackgroundTexture;
    sf::Texture heartTexture;

    void loadFonts();
    void loadTextures();
};

#endif
