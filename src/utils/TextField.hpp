/*
 * Bulletline
 *
 * (c) 2016 Jakub Powierza & Karolina Olszewska
 *
 */

#ifndef TextField_hpp
#define TextField_hpp

#include <SFML/Graphics.hpp>

#include "../core/CommonData.hpp"
#include "../Definitions.hpp"
#include "Label.hpp"

class TextField {
private:
    Label* m_label;
    float m_positionX;
    float m_positionY;
    sf::RectangleShape m_textField;
public:
    bool m_inputFlag;
    
public:
    // Constructors
    TextField();
    TextField(float positionX, float positionY, CommonData* commonData);

    // Core
    void draw(sf::RenderWindow& window);
    bool cursorInRange(sf::Vector2i position);

    // Getters
    string getText();

    // Setters
    void setText(string text);
    void setOutline(sf::Color color);
};

#endif
