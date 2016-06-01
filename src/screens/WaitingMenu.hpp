/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef WaitingMenu_hpp
#define WaitingMenu_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Definitions.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Button.hpp"
#include "../utils/Label.hpp"
#include "../utils/Converter.hpp"
#include "../levels/LevelOne.hpp"
#include "../network/Connection.hpp"

class WaitingMenu : public Screen {
public:
    // Constructors
    WaitingMenu();
    ~WaitingMenu();

    // Core
    void before(sf::RenderWindow &window, CommonData* commonData);
    int run(sf::RenderWindow &window, CommonData* commonData);
    void after(sf::RenderWindow &window, CommonData* commonData);
};

#endif