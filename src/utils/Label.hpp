/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef Label_hpp
#define Label_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Definitions.hpp"

using namespace std;

class Label {
private:
    string m_text;
    int m_fontSize;
    float m_positionX;
    float m_positionY;
    sf::Color m_color;
    sf::Font m_font;
    sf::Text m_label;

public:
    // Constructors
    Label();
    Label(string text, int fontSize, float positionX, float positionY);

    // Core
    void draw(sf::RenderWindow& window);

    // Getters
    float getWidth();
    float getHeight();

    // Setters
    void setPosition(float posX, float posY);
    void setString(string string);
};

#endif
