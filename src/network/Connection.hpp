/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Connection_hpp
#define Connection_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "../core/Bullet.hpp"
#include "../core/Player.hpp"
#include "../core/CommonData.hpp"

using namespace std;

class Connection {
private:
    CommonData* m_commonData;
    sf::UdpSocket m_server;
    sf::IpAddress m_serverIP;
    unsigned short m_serverPort;
    
public:
    Connection(sf::IpAddress serverIP, unsigned short serverPort, CommonData* commonData);
    void sendPlayerUpdate(Player* player);
    void sendPlayerIntroduction(Player* player);
    void sendPlayerShot(Bullet* bullet);
    void run();
};

#endif
