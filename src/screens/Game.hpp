/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */  

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Graphics.hpp>
#include <sstream>

#include "../Definitions.hpp"
#include "../core/Player.hpp"
#include "../levels/LevelOne.hpp"
#include "../utils/Converter.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"

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