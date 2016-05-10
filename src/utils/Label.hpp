/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef Label_hpp
#define Label_hpp

#include <iostream>
#include <SFML/Graphics.hpp>\

using namespace std;

class Label {
private:
    string m_text;
    int m_fontSize;
    int m_positionX;
    int m_positionY;
    sf::Color m_color;
    sf::Font m_font;
    sf::Text m_label;

public:
    // Constructors
    Label();
    Label(string text, int fontSize, int positionX, int positionY, sf::Color color);

    // Core
    void draw(sf::RenderWindow& window);
};

#endif
