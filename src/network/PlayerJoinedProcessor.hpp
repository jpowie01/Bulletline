/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef PlayerJoinedProcessor_hpp
#define PlayerJoinedProcessor_hpp

#include "../core/Processor.hpp"
#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class PlayerJoinedProcessor : public Processor {
public:
    void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData);
};

#endif
