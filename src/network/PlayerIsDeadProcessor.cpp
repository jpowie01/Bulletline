/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerIsDeadProcessor.hpp"

void PlayerIsDeadProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 id;
    data >> id;
    
    // Get player
    Player* player = commonData->map->getPlayerWithID((int)id);
    
    // Set dead
    player->setDead();
    
    // Log
    cout << "Player is dead (Name: " << player->getName() << " ID: " << player->getID() << " TeamID: " << player->getTeamID() << ")\n";
}
