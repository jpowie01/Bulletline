/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#include "EndOfTheGameProcessor.hpp"

void EndOfTheGameProcessor::process(sf::Packet data, sf::IpAddress sender, short port, CommonData *commonData) {
    // Unpack data
    sf::Uint8 winningTeam;
    data >> winningTeam;
    
    // Set winning team
    commonData->gameEnded = true;
    commonData->winningTeam = (int)winningTeam;
    
    // Log
    cout << "End of the game! Winning team ID: " << (int)winningTeam << "\n";
}
