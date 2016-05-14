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
    this->m_color = DEFAULT_BUTTON_COLOR;

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

Button::Button(string text, int normalfontSize, int largerFontSize, float positionX, float positionY) {
    this->m_text = text;
    this->m_normalFontSize = normalfontSize;
    this->m_largerFontSize = largerFontSize;
    this->m_positionX = positionX;
    this->m_positionY = positionY;
    this->m_color = DEFAULT_BUTTON_COLOR;

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

bool Button::cursorInRange(sf::Vector2i position) {
    float width = this->m_button.getGlobalBounds().width;
    float height = this->m_button.getGlobalBounds().height;

    if (position.x >= this->m_positionX && position.x < width + this->m_positionX &&
        position.y >= this->m_positionY && position.y < height + this->m_positionY) {
        return true;
    }
    return false;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(m_button);
}

void Button::changeColor(sf::Color color) {
    this->m_button.setColor(color);
}

void Button::setDefaultColor() {
    this->m_button.setColor(DEFAULT_BUTTON_COLOR);
}