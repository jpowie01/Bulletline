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

#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

using namespace std;

class Button {
private:
    string m_text;
    int m_normalFontSize;
    float m_positionX;
    float m_positionY;
    sf::Color m_color;
    sf::Text m_button;

public:
    // Constructors
    Button();
    Button(string text, int normalfontSize, float positionX, float positionY, CommonData* commonData);

    // Core
    bool cursorInRange(sf::Vector2i position);
    void draw(sf::RenderWindow& window);
    void changeColor(sf::Color color);
    void setDefaultColor();
};

#endif
