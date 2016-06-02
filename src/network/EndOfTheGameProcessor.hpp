/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef EndOfTheGameProcessor_hpp
#define EndOfTheGameProcessor_hpp

#include "../core/Processor.hpp"
#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class EndOfTheGameProcessor : public Processor {
public:
    void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData);
};

#endif
