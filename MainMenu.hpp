#ifndef MainMenu_hpp
#define MainMenu_hpp

#include "Screen.hpp"

#include <SFML\Graphics.hpp>

class MainMenu: public Screen {
private:
    bool playing;
public:
    MainMenu();
    ~MainMenu();
    int run(sf::RenderWindow &window);
};

#endif