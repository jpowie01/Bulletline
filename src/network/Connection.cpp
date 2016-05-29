/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "Connection.hpp"

Connection::Connection(sf::IpAddress serverIP, unsigned short serverPort, CommonData* commonData) {
    // Initialize
    this->m_commonData = commonData;
    this->m_serverIP = serverIP;
    this->m_serverPort = serverPort;
    
    // Bind port for listening
    if (m_server.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
        printf("Cannot bind port!");
        return;
    }
}

//void Connection::sendPlayerUpdate(Player* player) {
//    // Prepare data to send
//    sf::Packet data;
//    data << sf::Uint8(PLAYER_HEADER);
//    data << player->getX();
//    data << player->getY();
//
//    // Send data
//    if (this->m_server.send(data, this->m_serverIP, this->m_serverPort) != sf::Socket::Done) {
//        printf("Error sending data to server!");
//        return;
//    }
//}

void Connection::sendPlayerIntroduction(Player* player) {
    // Prepare data
    sf::Packet data;
    sf::Uint8 header = NETWORK_PLAYER_INTRODUCTION_HEADER;
    data << header;
    data << player->getName();

    // Send data to the server
    if (this->m_server.send(data, this->m_serverIP, this->m_serverPort) != sf::Socket::Done) {
        printf("Error sending data to server!");
        return;
    }
}

void Connection::run() {
    // Containers for data
    sf::Packet data;
    sf::IpAddress sender;
    unsigned short port;

    // Listen for data
    while (true) {
        // Receive data
        if (this->m_server.receive(data, sender, port) != sf::Socket::Done) {
            cout << "Error receiving data from " << sender << ":" << port << "\n";
            continue;
        }

        // Process data
        sf::Uint8 header;
        data >> header;
        if (header == NETWORK_PLAYER_JOINED_GAME_HEADER) {
            // Unpack data
            sf::Uint8 ID, teamID, amountOfPlayers;
            string name;
            data >> ID;
            data >> teamID;
            data >> amountOfPlayers;

            // Log
            cout << "Joined game (ID: " << (int)ID << " TeamID: " << (int)teamID << " InGame: " << (int)amountOfPlayers << ")\n";

            // Set data
            this->m_commonData->mainPlayer->setID((int)ID);
            this->m_commonData->mainPlayer->setTeamID((int)teamID);
            for (int i = 0; i < (int)amountOfPlayers - 1; i++) {
                // Unpack data
                data >> ID;
                data >> teamID;
                data >> name;

                // Add new player
                Player* player = new Player(false, 0, 0, m_commonData->map);
                player->setID((int)ID);
                player->setTeamID((int)teamID);
                player->setName(name);
                m_commonData->map->addPlayer(player);

                // Log
                cout << "Other player added (Name: " << player->getName() << " ID: " << player->getID() << " TeamID: " << player->getTeamID() << ")\n";
            }
        } else if (header == NETWORK_PLAYER_JOINED_HEADER) {
            // Unpack data
            sf::Uint8 ID, teamID;
            string name;
            data >> ID;
            data >> teamID;
            data >> name;

            // Add new player
            Player* player = new Player(false, 0, 0, m_commonData->map);
            player->setID((int)ID);
            player->setTeamID((int)teamID);
            player->setName(name);
            m_commonData->map->addPlayer(player);

            // Log
            cout << "New player came (Name: " << player->getName() << " ID: " << player->getID() << " TeamID: " << player->getTeamID() << ")\n";
        } else {
            cout << "Unknown header!\n";
        }
    }
}
