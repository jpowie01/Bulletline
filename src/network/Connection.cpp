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

void Connection::sendPlayerUpdate(Player* player) {
    // Prepare data to send
    sf::Packet data;
    sf::Uint8 header = NETWORK_PLAYER_UPDATE_HEADER;
    sf::Uint8 id = player->getID();
    data << header << id << player->getX() << player->getY();

    // Send data
    if (this->m_server.send(data, this->m_serverIP, this->m_serverPort) != sf::Socket::Done) {
        printf("Error sending data to server!");
        return;
    }
}

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

void Connection::sendPlayerShot(Bullet* bullet) {
    // Prepare data to send
    sf::Packet data;
    sf::Uint8 header = NETWORK_PLAYER_SHOT_HEADER;
    sf::Uint8 id = bullet->getPlayer()->getID();
    data << header << id << bullet->getX() << bullet->getY() << bullet->getDirectionX() << bullet->getDirectionY() << bullet->getSpeed();
    
    // Send data
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
        if (header == NETWORK_JOINED_GAME_HEADER) {
            // Unpack data
            sf::Uint8 ID, teamID, amountOfPlayers;
            string name;
            data >> ID;
            data >> teamID;
            data >> amountOfPlayers;

            // Set flag in common data
            this->m_commonData->joinedGame = true;

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
        } else if (header == NETWORK_START_GAME_HEADER) {
            // Get information about players position
            for (int i = 0; i < m_commonData->map->playersSize(); i++) {
                sf::Uint8 id;
                sf::Uint32 x, y;
                data >> id >> x >> y;
                Player* player = m_commonData->map->getPlayerWithID((int)id);
                player->setX((int)x);
                player->setY((int)y);
            }

            // Start game
            this->m_commonData->gameStarted = true;
        } else if (header == NETWORK_ALL_PLAYERS_UPDATE_HEADER) {
            // Update information
            sf::Uint8 id, health;
            float x, y;
            for (int i = 0; i < m_commonData->map->playersSize(); i++) {
                data >> id >> x >> y >> health;
                Player* player = m_commonData->map->getPlayerWithID((int)id);
                if (player != m_commonData->mainPlayer) {
                    player->setPosition(x, y);
                }
                player->setHealth((int)health);
            }
        } else if (header == NETWORK_NEW_BULLET_HEADER) {
            // Unpack data
            sf::Uint8 id;
            float x, y;
            float directionX, directionY;
            float speed;
            data >> id >> x >> y >> directionX >> directionY >> speed;
            
            // Get player
            Player* player = m_commonData->map->getPlayerWithID((int)id);
            
            // Create bullet
            Bullet* bullet = new Bullet(x, y, directionX, directionY, player);
            m_commonData->map->addBullet(bullet);
        } else if (header == NETWORK_PLAYER_IS_DEAD_HEADER) {
            // Unpack data
            sf::Uint8 id;
            data >> id;

            // Get player
            Player* player = m_commonData->map->getPlayerWithID((int)id);

            // Set dead
            player->setDead();

            // Main player is dead
            if (player == m_commonData->mainPlayer) {
                // DEAD SCREEN SOMEHOW
            }
        } else {
            cout << "Unknown header!\n";
        }
    }
}
