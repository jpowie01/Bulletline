/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "AllPlayersUpdateProcessor.hpp"

void AllPlayersUpdateProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Update information
    sf::Uint8 id, health;
    float x, y;
    for (int i = 0; i < commonData->map->playersSize(); i++) {
        data >> id >> x >> y >> health;
        Player* player = commonData->map->getPlayerWithID((int)id);
        if (player != commonData->mainPlayer) {
            player->setPosition(x, y);
        }
        player->setHealth((int)health);
    }
}
