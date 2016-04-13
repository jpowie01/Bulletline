/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <SFML/Graphics.hpp>

#include "Screen.hpp"
#include "../Definitions.hpp"

class MainMenu: public Screen {
public:
    // Constructors
    MainMenu();
    ~MainMenu();
    
    // Core
    void before(sf::RenderWindow &window);
    int run(sf::RenderWindow &window);
    void after(sf::RenderWindow &window);
};

#endif