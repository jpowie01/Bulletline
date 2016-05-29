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
    this->m_fontSize = 0;
    this->m_positionX = 0;
    this->m_positionY = 0;
    this->m_color = DEFAULT_BUTTON_COLOR;
}

Button::Button(string text, int fontSize, CommonData* commonData) : Button(text, fontSize, NULL, NULL, commonData) {}

Button::Button(string text, int fontSize, float positionX, float positionY, CommonData* commonData) {
    this->m_text = text;
    this->m_fontSize = fontSize;
    this->m_positionX = positionX;
    this->m_positionY = positionY;
    this->m_color = DEFAULT_BUTTON_COLOR;

    // Set button
    m_button.setFont(commonData->bebasNeueFont);
    m_button.setString(this->m_text);
    m_button.setCharacterSize(this->m_fontSize);
    m_button.setPosition(this->m_positionX, this->m_positionY);
    m_button.setColor(this->m_color);
}

//================================================================================
// Core
//================================================================================

bool Button::cursorInRange(sf::Vector2i position) {
    if (this->m_button.getGlobalBounds().contains(position.x, position.y)) {
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
//================================================================================
// Getters
//================================================================================

float Button::getWidth() {
    return this->m_button.getGlobalBounds().width;
}

//================================================================================
// Setters
//================================================================================

void Button::setDefaultColor() {
    this->m_button.setColor(DEFAULT_BUTTON_COLOR);
}

void Button::setPosition(float posX, float posY) {
    this->m_positionX = posX;
    this->m_positionY = posY;
    this->m_button.setPosition(m_positionX, m_positionY);
}
