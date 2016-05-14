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
    if (m_server.bind(54001) != sf::Socket::Done) {
        printf("Cannot bind port!");
        return;
    }
}

void Connection::sendPlayerUpdate(Player* player) {
    // Prepare data to send
    sf::Packet data;
    data << sf::Uint8(PLAYER_HEADER);
    data << player->getX();
    data << player->getY();
    
    // Send data
    if (this->m_server.send(data, this->m_serverIP, this->m_serverPort) != sf::Socket::Done) {
        printf("Error sending data to server!");
        return;
    }
}

void Connection::run() {
    // Listen for data
    while (true) {
        printf("get data from server that is not sending yet\n");
        sf::sleep(sf::seconds(1.0f));
    }
}
