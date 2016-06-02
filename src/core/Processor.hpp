/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Processor_hpp
#define Processor_hpp

#include <iostream>
#include <SFML/Network.hpp>

#include "CommonData.hpp"

using namespace std;

class Processor {
public:
    virtual void process(sf::Packet data, sf::IpAddress sender, short port, CommonData* commonData) = 0;
};

#endif
