/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "JoinedGameProcessor.hpp"

void JoinedGameProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData) {
    // Unpack data
    sf::Uint8 ID, teamID, amountOfPlayers;
    string name;
    data >> ID;
    data >> teamID;
    data >> amountOfPlayers;
    
    // Set flag in common data
    commonData->joinedGame = true;
    
    // Log
    cout << "Joined game (ID: " << (int)ID << " TeamID: " << (int)teamID << " InGame: " << (int)amountOfPlayers << ")\n";
    
    // Set data
    commonData->mainPlayer->setID((int)ID);
    commonData->mainPlayer->setTeamID((int)teamID);
    for (int i = 0; i < (int)amountOfPlayers - 1; i++) {
        // Unpack data
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
        cout << "Other player added (Name: " << player->getName() << " ID: " << player->getID() << " TeamID: " << player->getTeamID() << ")\n";
    }
}
