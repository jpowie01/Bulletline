/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Definitions.hpp"

using namespace std;

class Button {
private:
    string m_text;
    int m_normalFontSize;
    int m_largerFontSize;
    float m_positionX;
    float m_positionY;
    sf::Color m_color;
    sf::Font m_font;
    sf::Text m_button;

public:
    // Constructors
    Button();
    Button(string text, int normalfontSize, int largerFontSize, float positionX, float positionY);

    // Core
    bool cursorInRange(sf::Vector2i position);
    void draw(sf::RenderWindow& window);
    void changeColor(sf::Color color);
    void setDefaultColor();
};

#endif
