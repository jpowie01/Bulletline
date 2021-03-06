/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Definitions.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Button.hpp"
#include "../utils/Label.hpp"
#include "../network/Connection.hpp"

class MainMenu: public Screen {
public:
    // Constructors
    MainMenu();
    ~MainMenu();
    
    // Core
    void before(sf::RenderWindow &window, CommonData* commonData);
    int run(sf::RenderWindow &window, CommonData* commonData);
    void after(sf::RenderWindow &window, CommonData* commonData);
};

#endif
