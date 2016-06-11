/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "StartGameProcessor.hpp"

void StartGameProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Get information about players position
    for (int i = 0; i < commonData->map->playersSize(); i++) {
        sf::Uint8 id;
        sf::Uint32 x, y;
        data >> id >> x >> y;
        Player* player = commonData->map->getPlayerWithID((int)id);
        player->setX((int)x);
        player->setY((int)y);
    }
    
    // Start game
    commonData->gameStarted = true;
    
    // Log
    cout << "Game started!\n";
}
