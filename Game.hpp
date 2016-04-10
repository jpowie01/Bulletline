#ifndef Game_hpp
#define Game_hpp

#include "Screen.hpp"
#include <SFML/Graphics.hpp>

class Game : public Screen {

public:
    Game();
    ~Game();
    int run(sf::RenderWindow& window);
};

#endif