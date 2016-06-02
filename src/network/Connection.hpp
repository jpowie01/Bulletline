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

#include "JoinedGameProcessor.hpp"
#include "PlayerJoinedProcessor.hpp"
#include "StartGameProcessor.hpp"
#include "AllPlayersUpdateProcessor.hpp"
#include "NewBulletProcessor.hpp"
#include "PlayerIsDeadProcessor.hpp"
#include "EndOfTheGameProcessor.hpp"

using namespace std;

class Connection {
private:
    // Data
    CommonData* m_commonData;
    sf::UdpSocket m_server;
    sf::IpAddress m_serverIP;
    unsigned short m_serverPort;
    
    // Processors
    JoinedGameProcessor* joinedGameProcessor;
    PlayerJoinedProcessor* playerJoinedProcessor;
    StartGameProcessor* startGameProcessor;
    AllPlayersUpdateProcessor* allPlayersUpdateProcessor;
    NewBulletProcessor* newBulletProcessor;
    PlayerIsDeadProcessor* playerIsDeadProcessor;
    EndOfTheGameProcessor* endOfTheGameProcessor;

public:
    Connection(sf::IpAddress serverIP, unsigned short serverPort, CommonData* commonData);
    void sendPlayerUpdate(Player* player);
    void sendPlayerIntroduction(Player* player);
    void sendPlayerShot(Bullet* bullet);
    void run();
};

#endif
