/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef AuthorsMenu_hpp
#define AuthorsMenu_hpp

#include <SFML/Graphics.hpp>

#include "../Definitions.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Button.hpp"
#include "../utils/Label.hpp"

class AuthorsMenu : public Screen {
public:
    // Constructors
    AuthorsMenu();
    ~AuthorsMenu();

    // Core
    void before(sf::RenderWindow &window, CommonData* commonData);
    int run(sf::RenderWindow &window, CommonData* commonData);
    void after(sf::RenderWindow &window, CommonData* commonData);
};

#endif
