#ifndef Screen_hpp
#define Screen_hpp

#include <SFML/Graphics.hpp>

class Screen {
public:
    // Core
    virtual void before(sf::RenderWindow &window) = 0;
    virtual int run(sf::RenderWindow &window) = 0;
    virtual void after(sf::RenderWindow &window) = 0;
};

#endif