/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef Screen_hpp
#define Screen_hpp

#include <SFML/Graphics.hpp>
#include "CommonData.hpp"

class Screen {
public:
    // Core
    virtual void before(sf::RenderWindow &window, CommonData* commonData) = 0;
    virtual int run(sf::RenderWindow &window, CommonData* commonData) = 0;
    virtual void after(sf::RenderWindow &window, CommonData* commonData) = 0;
};

#endif