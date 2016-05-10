/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/

#include "Button.hpp"
#include "../helpers/ResourcePath.hpp"

//================================================================================
// Constructors
//================================================================================

Button::Button() {
    this->m_text = "";
    this->m_normalFontSize = 0;
    this->m_largerFontSize = 0;
    this->m_positionX = 0;
    this->m_positionY = 0;
    this->m_color = sf::Color::White;

    // Load font
    if (!m_font.loadFromFile(resourcePath() + "assets/fonts/Arial.ttf")) {
        printf("Failed to load font file (Arial.ttf)");
        return;
    }

    // Set button
    m_button.setFont(m_font);
    m_button.setString(this->m_text);
    m_button.setCharacterSize(this->m_normalFontSize);
    m_button.setPosition(this->m_positionX, this->m_positionY);
    m_button.setColor(this->m_color);
}

Button::Button(string text, int normalfontSize, int largerFontSize, int positionX, int positionY, sf::Color color) {
    this->m_text = text;
    this->m_normalFontSize = normalfontSize;
    this->m_largerFontSize = largerFontSize;
    this->m_positionX = positionX;
    this->m_positionY = positionY;
    this->m_color = color;

    // Load font
    if (!m_font.loadFromFile(resourcePath() + "assets/fonts/BebasNeue.otf")) {
        printf("Failed to load font file (BebasNeue.otf)");
        return;
    }

    // Set button
    m_button.setFont(m_font);
    m_button.setString(this->m_text);
    m_button.setCharacterSize(this->m_normalFontSize);
    m_button.setPosition(this->m_positionX, this->m_positionY);
    m_button.setColor(this->m_color);
}

//================================================================================
// Core
//================================================================================

bool Button::cursorInRange(sf::Vector2i position, int coordinateX1, int coordinateX2, int coordinateY1, int coordinateY2) {
    if (position.x >= coordinateX1 && position.x < coordinateX2 &&
        position.y >= coordinateY1 && position.y < coordinateY2) {
        // Changing the color of button font if cursor is in range
        m_button.setColor(sf::Color::Red);
        return true;
    }
    // Setting color back to normal
    m_button.setColor(sf::Color::White);
    return false;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_button);
}
