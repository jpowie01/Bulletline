/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#ifndef Button_hpp
#define Button_hpp

#include <iostream>
#include <SFML/Graphics.hpp>\

using namespace std;

class Button {
private:
    string m_text;
    int m_normalFontSize;
    int m_largerFontSize;
    int m_positionX;
    int m_positionY;
    sf::Color m_color;
    sf::Font m_font;
    sf::Text m_button;

public:
    // Constructors
    Button();
    Button(string text, int normalfontSize, int largerFontSize, int positionX, int positionY, sf::Color color);

    // Core
    bool cursorInRange(sf::Vector2i position, int coordinateX1, int coordinateX2, int coordinateY1, int coordinateY2);
    void draw(sf::RenderWindow& window);
};

#endif
