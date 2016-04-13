/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */  

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>

#include "Screen.hpp"

class Game : public Screen {

public:
    // Constructors
    Game();
    ~Game();
    
    // Core
    void before(sf::RenderWindow &window);
    int run(sf::RenderWindow &window);
    void after(sf::RenderWindow &window);
};

#endif