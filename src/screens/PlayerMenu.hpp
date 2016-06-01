/*
 * Counter Strike 2D
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef PlayerMenu_hpp
#define PlayerMenu_hpp

#include <SFML/Graphics.hpp>

#include "../Definitions.hpp"
#include "../helpers/ResourcePath.hpp"
#include "../core/Screen.hpp"
#include "../utils/Button.hpp"
#include "../utils/TextField.hpp"
#include "../utils/Label.hpp"
#include "../utils/Converter.hpp"
#include "../network/Connection.hpp"

class PlayerMenu : public Screen {
public:
    // Constructors
    PlayerMenu();
    ~PlayerMenu();

    // Core
    void before(sf::RenderWindow &window, CommonData* commonData);
    int run(sf::RenderWindow &window, CommonData* commonData);
    void after(sf::RenderWindow &window, CommonData* commonData);
};

#endif
