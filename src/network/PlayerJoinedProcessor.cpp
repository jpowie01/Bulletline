/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "PlayerJoinedProcessor.hpp"

void PlayerJoinedProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 ID, teamID;
    string name;
    data >> ID;
    data >> teamID;
    data >> name;
    
    // Add new player
    Player* player = new Player(false, 0, 0, commonData->map);
    player->setID((int)ID);
    player->setTeamID((int)teamID);
    player->setName(name);
    commonData->map->addPlayer(player);
    
    // Log
    cout << "New player came (Name: " << player->getName() << " ID: " << player->getID() << " TeamID: " << player->getTeamID() << ")\n";
}
