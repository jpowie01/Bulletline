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
    
    // Create processors
    this->joinedGameProcessor = new JoinedGameProcessor();
    this->playerJoinedProcessor = new PlayerJoinedProcessor();
    this->startGameProcessor = new StartGameProcessor();
    this->allPlayersUpdateProcessor = new AllPlayersUpdateProcessor();
    this->newBulletProcessor = new NewBulletProcessor();
    this->playerIsDeadProcessor = new PlayerIsDeadProcessor();
    this->endOfTheGameProcessor = new EndOfTheGameProcessor();
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
            this->joinedGameProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_PLAYER_JOINED_HEADER) {
            this->playerJoinedProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_START_GAME_HEADER) {
            this->startGameProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_ALL_PLAYERS_UPDATE_HEADER) {
            this->allPlayersUpdateProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_NEW_BULLET_HEADER) {
            this->newBulletProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_PLAYER_IS_DEAD_HEADER) {
            this->playerIsDeadProcessor->process(data, sender, port, m_commonData);
        } else if (header == NETWORK_END_OF_THE_GAME_HEADER) {
            this->endOfTheGameProcessor->process(data, sender, port, m_commonData);
        } else {
            cout << "Unknown header!\n";
        }
    }
}
