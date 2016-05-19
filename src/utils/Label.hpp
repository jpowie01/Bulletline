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

#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class Label {
private:
    string m_text;
    int m_fontSize;
    float m_positionX;
    float m_positionY;
    sf::Color m_color;
    sf::Text m_label;

public:
    // Constructors
    Label();
    Label(string text, int fontSize, float positionX, float positionY, CommonData* commonData);

    // Core
    void draw(sf::RenderWindow& window);

    // Getters
    float getWidth();
    float getHeight();
    string getString();

    // Setters
    void setPosition(float posX, float posY);
    void setString(string string);
    void setColor(sf::Color color);
};

#endif
