/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef StartGameProcessor_hpp
#define StartGameProcessor_hpp

#include "../core/Processor.hpp"
#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class StartGameProcessor : public Processor {
public:
    void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData);
};

#endif
