/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */  

#ifndef Game_hpp
#define Game_hpp

#include <sstream>
#include <SFML/Graphics.hpp>
#include <sstream>

#include "../Definitions.hpp"
#include "../core/Player.hpp"
#include "../levels/LevelOne.hpp"
#include "../utils/Converter.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Label.hpp"
#include "../utils/Button.hpp"
#include "../network/Connection.hpp"

using namespace std;

class Game : public Screen {

public:
    // Constructors
    Game();
    ~Game();
    
    // Core
    void before(sf::RenderWindow &window, CommonData* commonData);
    int run(sf::RenderWindow &window, CommonData* commonData);
    void after(sf::RenderWindow &window, CommonData* commonData);
};

#endif