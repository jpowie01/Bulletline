#ifndef Screen_hpp
#define Screen_hpp

#include <SFML\Graphics.hpp>

class Screen {
public:
    virtual int run(sf::RenderWindow &window) = 0;
};

#endif