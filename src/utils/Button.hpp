/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>

#include "../core/CommonData.hpp"
#include "../Definitions.hpp"

class Button {
private:
    string m_text;
    int m_fontSize;
    float m_positionX;
    float m_positionY;
    sf::Color m_color;
    sf::Text m_button;

public:
    // Constructors
    Button();
    Button(string text, int fontSize, CommonData* commonData);
    Button(string text, int fontSize, float positionX, float positionY, CommonData* commonData);

    // Core
    bool cursorInRange(sf::Vector2i position);
    void draw(sf::RenderWindow& window);
    void changeColor(sf::Color color);

    // Geters
    float getWidth();

    // Setters
    void setDefaultColor();
    void setPosition(float posX, float posY);
};

#endif
