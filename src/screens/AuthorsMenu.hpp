/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef AuthorsMenu_hpp
#define AuthorsMenu_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Definitions.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Button.hpp"

class AuthorsMenu : public Screen {
public:
    // Constructors
    AuthorsMenu();
    ~AuthorsMenu();

    // Core
    void before(sf::RenderWindow &window);
    int run(sf::RenderWindow &window);
    void after(sf::RenderWindow &window);
};

#endif