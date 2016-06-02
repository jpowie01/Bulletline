/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "NewBulletProcessor.hpp"

void NewBulletProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 id;
    float x, y;
    float directionX, directionY;
    float speed;
    data >> id >> x >> y >> directionX >> directionY >> speed;
    
    // Get player
    Player* player = commonData->map->getPlayerWithID((int)id);
    
    // Create bullet
    Bullet* bullet = new Bullet(x, y, directionX, directionY, player);
    commonData->map->addBullet(bullet);
}
